#include "ChessComposition.h"
#include "Mediator.h"

enum SquareType {
	YIZHAN = 1 << 1,		//驿站
	BINGYING = 1 << 2,		//兵营
	BINGZHAN = 1 << 3,		//兵站
	JUNYING = 1 << 4,		//军营
	QITA = 0				//其他
};
enum ChessType {
	CHESS00,	//炸弹	2
	CHESS31,	//地雷	3
	CHESS32,	//工兵	3
	CHESS33,	//排长	3
	CHESS34,	//连长	3
	CHESS35,	//营长	2
	CHESS36,	//团长	2
	CHESS37,	//旅长	2
	CHESS38,	//师长	2
	CHESS39,	//军长	1
	CHESS40,	//司令	1
	CHESS41		//军棋	1
};

TCHAR ChessName[12][5] = {
	_T("炸"),
	_T("雷"),
	_T("兵"),
	_T("排"),
	_T("连"),
	_T("营"),
	_T("团"),
	_T("旅"),
	_T("师"),
	_T("军"),
	_T("司"),
	_T("旗")
};

TCHAR Lables[18][5] = {
	_T("大"),
	_T("中"),
	_T("小"),

	_T("！"),
	_T("？"),
	_T("-"),

	_T("兵"),
	_T("排"),
	_T("连"),

	_T("营"),
	_T("团"),
	_T("旅"),

	_T("师"),
	_T("军"),
	_T("司"),

	_T("炸"),
	_T("雷"),
	_T("旗")
};

int Colors[4] = { YELLOW ,BLUE ,RED,PURPLE };

const char *TYPE_FILE_NAME = "SquareTypeData.txt";
const char *DIRECTION_FILE_NAME = "SquareDirectionData.txt";
const char *POSITION_FILE_NAME = "ChessPiecesPositionData.txt";
const char *NUMBER_FILE_NAME = "ChessPiecesNumberData.txt";

ChessComposition::ChessComposition(Mediator *mediator1)
{
	mediator = mediator1;
	mediator->SetCCst(this);
	ordernum = mediator->GetOrdernum();

	loadimage(&img, _T("test.bmp"), 800, 800);
	InitSquare();
	InitChessPieces();
}

ChessComposition::~ChessComposition()
{

}

void ChessComposition::Update()
{
	putimage(0, 0, &img);
	Draw();
}

void ChessComposition::Draw()
{
	for (int i = 0; i < 4; i++)
	{
		//判断存活 准备
		if (i != ordernum && !mediator->RsPlayerReady(i))
		{
			continue;
		}
		for (int j = 0; j < 25; j++)
		{
			if (chesspieces[i][j].viable)
			{
				setfillcolor(Colors[chesspieces[i][j].camp]);
				int logicx, logicy;
				PposiToLposi(chesspieces[i][j].cx, chesspieces[i][j].cy, logicx, logicy);
				if (logicy < 7 || logicy>11)
				{
					fillrectangle(20 + logicy * 40, 15 + logicx * 40, 40 + logicy * 40, 45 + logicx * 40);//纵向的矩形
				}
				else
				{
					fillrectangle(15 + logicy * 40, 20 + logicx * 40, 45 + logicy * 40, 40 + logicx * 40);//横向的矩形
				}
				if (chesspieces[i][j].camp == ordernum)
				{
					setcolor(BLACK);
					outtextxy(23 + logicy * 40, 23 + logicx * 40, ChessName[chesspieces[i][j].number]);
					setcolor(WHITE);
				}

				if (chesspieces[i][j].label >= 0)
				{
					setfillcolor(WHITE);
					fillrectangle(22 + logicy * 40, 22 + logicx * 40, 38 + logicy * 40, 38 + logicx * 40);//横向的矩形
					setcolor(BLACK);
					outtextxy(23 + logicy * 40, 23 + logicx * 40, Lables[chesspieces[i][j].label]);
					setcolor(WHITE);
				}
			}
		}
	}
}

void ChessComposition::InitSquare()
{
	//初始化棋盘  其中棋格的类型和方向从文件中获取
	ifstream typein;
	typein.open(TYPE_FILE_NAME, ios::in);
	if (!typein.is_open())
	{
		exit(0);
	}
	ifstream directionin;
	directionin.open(DIRECTION_FILE_NAME, ios::in);
	if (!directionin.is_open())
	{
		exit(0);
	}
	int squaretype = 0;
	int squaredirection = 0;
	for (int i = 0; i < SQUARE_ROW; i++)
	{
		for (int j = 0; j < SQUARE_ROW; j++)
		{
			typein >> squaretype;
			directionin >> squaredirection;
			squares[i][j].sx = i;
			squares[i][j].sy = j;
			squares[i][j].type = squaretype;
			squares[i][j].direction = squaredirection;
			squares[i][j].chesspieces = NULL;
		}
	}
}

void ChessComposition::InitChessPieces()
{
	//设置所有棋子  //初始化棋盘  其中棋格的类型和方向从文件中获取
	ifstream positionout;
	positionout.open(POSITION_FILE_NAME, ios::in);
	if (!positionout.is_open())
	{
		exit(0);
	}
	int px = 0;
	int py = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			positionout >> px;
			positionout >> py;
			chesspieces[i][j].cx = px;							//坐标
			chesspieces[i][j].cy = py;

			//	cout <<j << "->"<< px << "  " << py << endl;

			chesspieces[i][j].camp = i;							//阵营
			chesspieces[i][j].ismove = true;					//可移动	
			chesspieces[i][j].viable = true;					//存活
			chesspieces[i][j].number = -1;						//编号
			chesspieces[i][j].label = -1;						//标注
			squares[px][py].chesspieces = &chesspieces[i][j];	//棋格上的棋子
		}
		//	cout << endl;
	}
	positionout.close();
	//设置自己棋子的编号以及可移动性
	ifstream numberout;
	numberout.open(NUMBER_FILE_NAME, ios::in);
	if (!numberout.is_open())
	{
		exit(0);
	}
	int cnumber = 0;
	for (int i = 0; i < 25; i++)
	{
		numberout >> cnumber;
		chesspieces[ordernum][i].number = cnumber;
		if (cnumber == CHESS41 || cnumber == CHESS31)
		{
			chesspieces[ordernum][i].ismove = false;
		}
	}
	numberout.close();
}

void ChessComposition::LposiToPposi(int lx, int ly, int & px, int & py)
{
	LpToPp(ordernum, lx, ly, px, py);
}

void ChessComposition::PposiToLposi(int px, int py, int & lx, int & ly)
{
	PpToLp(ordernum, px, py, lx, ly);
}

ChessPieces * ChessComposition::GetChess(int x1, int y1)
{
	Square *square = GetSquare(x1, y1);
	if (square)
	{
		return square->chesspieces;
	}
	return NULL;
}

Square * ChessComposition::GetSquare(int x1, int y1)
{
	int rx = (y1 - 15) / 40;		//行
	int ry = (x1 - 15) / 40;		//列
	if (rx < 0 || rx >= SQUARE_ROW || ry < 0 || ry >= SQUARE_ROW)
	{
		return NULL;
	}
	//获取中心坐标
	int ox = 30 + ry * 40;
	int oy = 30 + rx * 40;

	//选择某个棋格
	if ((x1 - ox)*(x1 - ox) + (y1 - oy)*(y1 - oy) < 225)
	{
		//获取物理行列
		int px, py;
		LposiToPposi(rx, ry, px, py);
		return &squares[px][py];
	}
	return NULL;
}

bool ChessComposition::ExchangeChess(ChessPieces * cps1, ChessPieces * cps2)
{
	if (cps1->number == CHESS41 && !RsPutChess41(cps2->cx, cps2->cy) ||
		cps2->number == CHESS41 && !RsPutChess41(cps1->cx, cps1->cy) ||
		cps1->number == CHESS00 && !RsPutChess00(cps2->cx, cps2->cy) ||
		cps2->number == CHESS00 && !RsPutChess00(cps1->cx, cps1->cy) ||
		cps1->number == CHESS31 && !RsPutChess31(cps2->cx, cps2->cy) ||
		cps2->number == CHESS31 && !RsPutChess31(cps1->cx, cps1->cy))
	{
		return false;
	}
	//交换两棋子的位置
	int tempx = cps1->cx;
	int tempy = cps1->cy;
	cps1->cx = cps2->cx;
	cps1->cy = cps2->cy;
	cps2->cx = tempx;
	cps2->cy = tempy;
	//让相应的棋格刷新指向的棋子
	ChessPieces *tempcps = squares[cps1->cx][cps1->cy].chesspieces;
	squares[cps1->cx][cps1->cy].chesspieces = squares[cps2->cx][cps2->cy].chesspieces;
	squares[cps2->cx][cps2->cy].chesspieces = tempcps;
	return true;
}

bool ChessComposition::RsPutChess31(int x1, int y1)
{
	bool flag = true;
	switch (ordernum)
	{
	case 0:
		if (x1 > 2)
		{
			flag = false;
		}
		break;
	case 1:
		if (y1 > 2)
		{
			flag = false;
		}
		break;
	case 2:
		if (x1 < 16)
		{
			flag = false;
		}
		break;
	case 3:
		if (y1 < 16)
		{
			flag = false;
		}
		break;
	}
	if (!flag)
	{
		mediator->AddTip(_T("地雷无法移动到该位置"));
		return false;
	}
	return true;
}

void ChessComposition::SaveChessPosition()
{
	ofstream numberout;
	numberout.open(NUMBER_FILE_NAME, ios::out);
	if (!numberout.is_open())
	{
		exit(0);
	}

	int array[2][4] = { { 6,6,12,12 },{ 11,7,7,11 } };
	int dir[2][4] = { { -1,-1,1,1 },{ -1,1,1,-1 } };
	int x, y;
	for (int j = 0; j < 6; j++)
	{
		for (int k = 0; k < 5; k++)
		{
			if (ordernum % 2 == 0)
			{
				x = array[0][ordernum] + j * dir[0][ordernum];
				y = array[1][ordernum] + k * dir[1][ordernum];
			}
			else
			{
				y = array[0][ordernum] + j * dir[0][ordernum];
				x = array[1][ordernum] + k * dir[1][ordernum];
			}
			if (squares[x][y].type > 0 && squares[x][y].type != BINGYING)//棋盘的棋格 非兵营位置
			{
				numberout << space << squares[x][y].chesspieces->number << NEWLINE;
			}
		}
	}
	numberout.close();
}

bool ChessComposition::RsPutChess00(int x1, int y1)
{
	bool flag = true;
	switch (ordernum)
	{
	case 0:
		if (x1 == 6)
		{
			flag = false;
		}
		break;
	case 1:
		if (y1 == 6)
		{
			flag = false;
		}
		break;
	case 2:
		if (x1 == 12)
		{
			flag = false;
		}
		break;
	case 3:
		if (y1 == 12)
		{
			flag = false;
		}
		break;
	}
	if (!flag)
	{
		mediator->AddTip(_T("炸弹无法移动到该位置"));
		return false;
	}
	return true;
}

bool ChessComposition::RsPutChess41(int x1, int y1)
{
	int array[4][2][2] = {
	{ {  1, 1 },{  8,10 } },
	{ {  8,10 },{  1, 1 } },
	{ { 17,17 },{  8,10 } },
	{ {  8,10 },{ 17,17 } }
	};
	for (int i = 0; i < 2; i++)
	{
		if (x1 == array[ordernum][0][i] && y1 == array[ordernum][1][i])
		{
			return true;
		}
	}
	mediator->AddTip(_T("军棋无法移动到该位置"));
	return false;
}

bool ChessComposition::CanMoveChess(ChessPieces * cps1, Square * square1)
{
	//任务：判断棋子是否可以移动到目标棋格
	int ox = cps1->cx;
	int oy = cps1->cy;
	int tox = square1->sx;
	int toy = square1->sy;
	if (ox == tox && oy == toy)
	{
		mediator->AddTip(_T("不能原处移动"));
		return false;
	}
	if (!CanArrivePosition(cps1, square1))
	{
		mediator->AddTip(_T("目标地无法达到移动"));
		return false;
	}
	ChessPieces *cps2 = square1->chesspieces;
	if (cps2)
	{
		int camp1 = cps1->camp;
		int camp2 = cps2->camp;
		if ((camp1 + camp2) % 2 == 0)
		{
			mediator->AddTip(_T("目的地有我方棋子"));
			return false;
		}
		else
		{
			if (square1->type == BINGYING)
			{
				mediator->AddTip(_T("目的地的棋子受到保护"));
				return false;
			}
			else
			{
				//注：此部分为服务器返回后处理的逻辑
				int compresult = CompareChess(cps1->number, cps2->number);
				MoveChess(cps1, square1, compresult);
			}
		}
	}
	//注：此部分为服务器返回数据后处理的逻辑
	MoveChess(cps1, square1, 3);
	return true;
}

bool ChessComposition::CanArrivePosition(ChessPieces * cps1, Square * square1)
{
	//注：旧代码
	int x1 = cps1->cx;
	int y1 = cps1->cy;
	int x2 = square1->sx;
	int y2 = square1->sy;
	int lx1 = squares[x1][y1].type;
	int lx2 = square1->type;
	int biaoshi1 = cps1->number;

	int bianli[2][8] = { { 1,1,1,0,0,-1,-1,-1 },{ 1,0,-1,1,-1,1,0,-1 } };
	//根据地点1的棋格类型划分
	switch (lx1)
	{
		//驿站
	case YIZHAN:
		//直接往周围走
		if (abs(x1 - x2) < 2 && abs(y1 - y2) < 2)
		{
			if (lx2 == BINGYING)
				return true;
			if (x1 == x2 || y1 == y2)
				return true;
		}
		//不是往周围走
		//工兵的行走
		if (biaoshi1 == CHESS32)
		{
			if (lx1 == YIZHAN && lx2 == YIZHAN)
			{
				//构建用于寻路的二维表
				int tu[SQUARE_ROW][SQUARE_ROW];
				for (int i = 0; i < SQUARE_ROW; i++)
				{
					for (int j = 0; j < SQUARE_ROW; j++)
					{
						tu[i][j] = -1;
						if (!squares[i][j].chesspieces && squares[i][j].type == YIZHAN)
						{
							tu[i][j] = 0;
						}
					}
				}
				for (int k = 0; k < 3; k++)
				{
					//9为横向
					tu[7 + k * 2][8] = 0;
					tu[7 + k * 2][10] = 0;
					//10为纵向
					tu[8][7 + k * 2] = 0;
					tu[10][7 + k * 2] = 0;
				}
				if (Chess32FindWay(tu, x1, y1, x2, y2))
				{
					return true;
				}
			}
		}
		//非工兵
		else
		{
			//直接往周围走
			if (abs(x1 - x2) < 2 && abs(y1 - y2) < 2)
			{
				if (lx2 == BINGYING)
					return true;
				if (x1 == x2 || y1 == y2)
					return true;
			}
			//在铁路走
			if (CommonFindWay(x1, y1, x2, y2))
			{
				return true;
			}
		}
		break;
		//兵营
	case BINGYING:
		if (abs(x1 - x2) < 2 && abs(y1 - y2) < 2)
		{
			return true;
		}
		break;
		//兵站和军营
	case BINGZHAN:
	case JUNYING:
		if (abs(x1 - x2) < 2 && abs(y1 - y2) < 2)
		{
			if (lx2 == BINGYING)
				return true;
			if (x1 == x2 || y1 == y2)
				return true;
		}
		break;
	}
	return false;
}

bool ChessComposition::CommonFindWay(int x1, int y1, int x2, int y2)
{
	//注：旧代码
	int heng[6] = { 2,6,7,11,12,16 };
	for (int i = 0; i < 6; i++)
	{
		if (x1 == x2 && x1 == heng[i])
		{
			int min = y1 < y2 ? y1 : y2;
			int max = y1 < y2 ? y2 : y1;
			for (int j = min + 1; j <= max - 1; j++)
			{
				if (squares[x1][j].chesspieces)
				{
					return false;
				}
			}
			return true;
		}
		if (y1 == y2 && y1 == heng[i])
		{
			int min = x1 < x2 ? x1 : x2;
			int max = x1 < x2 ? x2 : x1;
			for (int j = min + 1; j <= max - 1; j++)
			{
				if (squares[j][y1].chesspieces)
				{
					return false;
				}
			}
			return true;
		}
	}
	//中心的竖线
	if (y1 == y2 && y1 == 9 && x1 > 5 && x1 < 13 && x2>5 && x2 < 13)
	{
		int min = x1 < x2 ? x1 : x2;
		int max = x1 < x2 ? x2 : x1;
		for (int j = min + 1; j <= max - 1; j++)
		{
			if (squares[j][y1].chesspieces)
			{
				return false;
			}
		}
		return true;
	}
	//中心的横线
	if (x1 == x2 && x1 == 9 && y1 > 5 && y1 < 13 && y2>5 && y2 < 13)
	{
		int min = y1 < y2 ? y1 : y2;
		int max = y1 < y2 ? y2 : y1;
		for (int j = min + 1; j <= max - 1; j++)
		{
			if (squares[x1][j].chesspieces)
			{
				return false;
			}
		}
		return true;
	}
	int pointx[4] = { 7,11,11,7 };
	int pointy[4] = { 7,7,11,11 };

	int dir[4][2][2] = {
		//左上
		{ { 0,-1 },{ -1,0 } },
		//左下
		{ { 0,1 },{ -1,0 } },
		//右下
		{ { 0,1 },{ 1,0 } },
		//右上
		{ { 0,-1 },{ 1,0 } }
	};
	for (int i = 0; i < 4; i++)
	{
		int n = 0;
		//记录在铁路的一段是否找到其中一个地点
		bool flag = false;
		for (int j = 1; j < 6; j++)
		{
			int x4 = pointx[i] + j * dir[i][0][0];
			int y4 = pointy[i] + j * dir[i][1][0];
			if (x1 == x4 && y1 == y4 || x2 == x4 && y2 == y4)
			{
				n++;
				break;
			}
			if (squares[x4][y4].chesspieces)
			{
				flag = true;
				break;
			}
		}
		if (flag)
			continue;
		for (int j = 1; j < 6; j++)
		{
			int x4 = pointx[i] + j * dir[i][0][1];
			int y4 = pointy[i] + j * dir[i][1][1];
			if (x1 == x4 && y1 == y4 || x2 == x4 && y2 == y4)
			{
				n++;
				break;
			}
			if (squares[x4][y4].chesspieces)
			{
				flag = true;
				break;
			}
		}
		if (n == 2)
			return true;
	}
	return false;
}

bool ChessComposition::Chess32FindWay(int tu[SQUARE_ROW][SQUARE_ROW], int x1, int y1, int x2, int y2)
{
	//注：旧代码
	int b8[2][8] = { { 1,1,-1,1,-1,-1,1,-1 },{ -1,1,-1,-1,1,-1,1,1 } };
	int b4[2][4] = { { -1,0,0,1 },{ 0,-1,1,0 } };
	int zy[2][2] = { { 0,0 },{ -1,1 } };
	int sx[2][2] = { { -1,1 },{ 0,0 } };
	int i = 0;
	stack<int> px;
	stack<int> py;
	px.push(x1);
	py.push(y1);
	tu[x1][y1] = -2;
	while (!px.empty())
	{
		int x = px.top();
		int y = py.top();
		bool flag = false;		//标记是否找到路了
		if (tu[x][y] != -1)
		{
			switch (squares[x][y].direction)
			{
			case 0:
				for (i = 0; i < 4; i++)
				{
					if (x + b4[0][i] == x2 && y + b4[1][i] == y2)
					{
						//保存路径
						return true;
					}
					if (tu[x + b4[0][i]][y + b4[1][i]] >= 0)//0为可走
					{
						px.push(x + b4[0][i]);
						py.push(y + b4[1][i]);
						tu[x + b4[0][i]][y + b4[1][i]] = -2;
						flag = true;		//找到路了
						break;
					}
				}
				break;
			case 9:
				//9为横向
				for (i = 0; i < 2; i++)
				{
					if (x + zy[0][i] == x2 && y + zy[1][i] == y2)
					{
						return true;
					}

					if (tu[x + zy[0][i]][y + zy[1][i]] >= 0)//0为可走
					{
						px.push(x + zy[0][i]);
						py.push(y + zy[1][i]);
						tu[x + zy[0][i]][y + zy[1][i]] = -2;
						flag = true;		//找到路了
						break;
					}
				}
				break;
			case 10:
				//纵向
				for (i = 0; i < 2; i++)
				{
					if (x + sx[0][i] == x2 && y + sx[1][i] == y2)
					{
						return true;
					}
					if (tu[x + sx[0][i]][y + sx[1][i]] >= 0)//0为可走
					{
						px.push(x + sx[0][i]);
						py.push(y + sx[1][i]);
						tu[x + sx[0][i]][y + sx[1][i]] = -2;
						flag = true;		//找到路了
						break;
					}
				}
				break;
			default:
				for (i = 0; i < 4; i++)
				{
					if (x + b4[0][i] == x2 && y + b4[1][i] == y2)
					{
						return true;
					}
					if (tu[x + b4[0][i]][y + b4[1][i]] >= 0)//0为可走
					{
						px.push(x + b4[0][i]);
						py.push(y + b4[1][i]);
						tu[x + b4[0][i]][y + b4[1][i]] = -2;
						flag = true;		//找到路了
						break;
					}
				}
				int x9 = x + b8[0][squares[x][y].direction - 1];
				int y9 = y + b8[1][squares[x][y].direction - 1];
				if (x9 == x2 && y9 == y2)
				{
					return true;
				}
				if (tu[x9][y9] >= 0)//0为可走
				{
					px.push(x9);
					py.push(y9);
					tu[x9][y9] = -2;
					flag = true;		//找到路了
					break;
				}
				break;
			}
		}
		if (!flag)//回退
		{
			px.pop();
			py.pop();
		}
	}
	return false;
}

void ChessComposition::MoveChess(ChessPieces * cps1, Square * square1, int movetype)
{
	//注：此部分应该是服务器的逻辑处理
	switch (movetype)
	{
	case 0://A干掉B
		squares[cps1->cx][cps1->cy].chesspieces = NULL;
		cps1->cx = square1->sx;
		cps1->cy = square1->sy;
		square1->chesspieces->viable = false;
		square1->chesspieces = cps1;
		break;
	case 1://A和B同归于尽
		cps1->viable = false;
		squares[cps1->cx][cps1->cy].chesspieces = NULL;
		square1->chesspieces->viable = false;
		square1->chesspieces = NULL;
		break;
	case 2://A被B干掉
		cps1->viable = false;
		squares[cps1->cx][cps1->cy].chesspieces = NULL;
		break;
	case 3://直接移动
		squares[cps1->cx][cps1->cy].chesspieces = NULL;
		cps1->cx = square1->sx;
		cps1->cy = square1->sy;
		square1->chesspieces = cps1;
		break;
	}
}

int ChessComposition::CompareChess(int g, int s)
{
	//注：此部分应该为服务器逻辑
	if (g == s || g == CHESS00 || s == CHESS00)
	{
		mediator->AddTip(_T("两棋同归于尽"));
		return 1;
	}
	if ((g == CHESS32 && s == CHESS31) || (g != CHESS00 && s == CHESS41) || (g > CHESS32 && g > s))
	{
		mediator->AddTip(_T("两棋A干掉B"));
		return 0;
	}
	if ((g < s) || (g != CHESS32 && g != CHESS00 && s == CHESS31))
	{
		mediator->AddTip(_T("两棋A被B干掉"));
		return 2;
	}
	return -1;
}

