#include"LifeGame.h"

int main()
{
	initgraph(NUMS * WIDTH , NUMS * WIDTH);
	Lifegame& game = Lifegame::onlyObject();
	MOUSEMSG m = GetMouseMsg();
	BeginBatchDraw();

	while (true)
	{
		if (MouseHit())
		{
			m = GetMouseMsg();
			if (m.mkRButton)
				break;
		}

		setfillcolor(BLACK);
		cleardevice();
		setfillcolor(WHITE);

		game.play();
		
		FlushBatchDraw();
		Sleep(TIME);
	}

	EndBatchDraw();
	closegraph();
	return 0;
}