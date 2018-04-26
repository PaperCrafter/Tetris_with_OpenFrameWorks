#include "ofApp.h"

#define up 72
#define left 75
#define right 77
#define down 88

ofImage Mapbrick;
ofImage MapImage1;
ofImage BlockB;
ofImage BlockG;
ofImage BlockO;
ofImage BlockP;
ofImage BlockR;
ofImage BlockS;
ofImage BlockY;
ofImage Blockbl;
ofImage opening;

ofTrueTypeFont text1;
ofTrueTypeFont text2;
ofTrueTypeFont text3;
ofTrueTypeFont text4;
ofTrueTypeFont text5;


//���� ���� ����ü
typedef struct info {
	int score;
	int highestScore;
}info;



int level = 1;
int gameOver;
int score;
int rotation;
int X, Y;
int xPos, yPos;
int nextX, nextY;
int curBlock;
int nextBlock;
int state = 0;
int gameStatus = 0;


int* block1;
int* block2;
int* maps;
int* mapsK;
int*(mapskk[4]);

//�⺻ ���� ũ��
float brickWidth = 40;
float brickHight = 40;

// �� �迭 ����
int Map[20][12] = {
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1 }
};

//��� �迭 ����
int blocks[7][4][4][4] = {

	{ //�׸���
		{ 0,0,0,0,
		0,1,1,0,
		0,1,1,0,
		0,0,0,0 },

		{ 0,0,0,0,
		0,1,1,0,
		0,1,1,0,
		0,0,0,0 },

		{ 0,0,0,0,
		0,1,1,0,
		0,1,1,0,
		0,0,0,0 },

		{ 0,0,0,0,
		0,1,1,0,
		0,1,1,0,
		0,0,0,0 }
	},


	{ //1�ں��
		{ 0,0,0,0,
		0,0,0,0,
		1,1,1,1,
		0,0,0,0 },

		{ 0,1,0,0,
		0,1,0,0,
		0,1,0,0,
		0,1,0,0 },

		{ 0,0,0,0,
		0,0,0,0,
		1,1,1,1,
		0,0,0,0 },

		{ 0,1,0,0,
		0,1,0,0,
		0,1,0,0,
		0,1,0,0 }
	},

	{ //z ���
		{ 0,0,0,0,
		1,1,0,0,
		0,1,1,0,
		0,0,0,0 },

		{ 0,0,0,0,
		0,0,1,0,
		0,1,1,0,
		0,1,0,0 },

		{ 0,0,0,0,
		1,1,0,0,
		0,1,1,0,
		0,0,0,0 },

		{ 0,0,0,0,
		0,0,1,0,
		0,1,1,0,
		0,1,0,0 }
	},

	{ //�ݴ� z��
		{ 0,0,0,0,
		0,1,1,0,
		1,1,0,0,
		0,0,0,0 },

		{ 0,0,0,0,
		1,0,0,0,
		1,1,0,0,
		0,1,0,0 },

		{ 0,0,0,0,
		0,1,1,0,
		1,1,0,0,
		0,0,0,0 },

		{ 0,0,0,0,
		1,0,0,0,
		1,1,0,0,
		0,1,0,0 }
	},

	{//���� ���
		{ 0,0,0,0,
		1,0,0,0,
		1,1,1,0,
		0,0,0,0 },

		{ 0,0,0,0,
		0,1,0,0,
		0,1,0,0,
		1,1,0,0 },

		{ 0,0,0,0,
		0,0,0,0,
		1,1,1,0,
		0,0,1,0 },

		{ 0,0,0,0,
		0,1,1,0,
		0,1,0,0,
		0,1,0,0 }
	},

	{ //�� ���� ���
		{ 0,0,0,0,
		0,0,1,0,
		1,1,1,0,
		0,0,0,0 },

		{ 0,0,0,0,
		1,1,0,0,
		0,1,0,0,
		0,1,0,0 },

		{ 0,0,0,0,
		0,0,0,0,
		1,1,1,0,
		1,0,0,0 },

		{ 0,0,0,0,
		0,1,0,0,
		0,1,0,0,
		0,1,1,0 }
	},

	{ //�� �� ���
		{ 0,0,0,0,
		0,1,0,0,
		1,1,1,0,
		0,0,0,0 },

		{ 0,0,0,0,
		0,1,0,0,
		0,1,1,0,
		0,1,0,0 },

		{ 0,0,0,0,
		0,0,0,0,
		1,1,1,0,
		0,1,0,0 },

		{ 0,0,0,0,
		0,1,0,0,
		1,1,0,0,
		0,1,0,0 }
	}
};

void drawMap();
void displayText();
void blockChoosing();
void appearBlock();
int displayBlock();

void drawTheStopedBlock();
void blockDelete();
void showNext();
void collideNot();
void move();
void levelUp();
void endGame();

//--------------------------------------------------------------
void ofApp::setup() {
	//��������
	ofSetWindowTitle("Tetris");
	ofSetFrameRate(30);
	ofSetWindowShape(1024, 800);
	ofBackground(ofColor::black);
	ofSetLineWidth(1);

	//�̹��� �ε�
	opening.load("interFace/opening.png");
	MapImage1.load("interFace/MapImage1.png");
	Mapbrick.load("interFace/MapBrick.png");

	//���̹��� �ε�
	BlockB.load("blocks/blueBlock.png");
	BlockG.load("blocks/greenBlock.png");
	BlockO.load("blocks/orangeBlock.png");
	BlockP.load("blocks/purpleBlock.png");
	BlockR.load("blocks/redBlock.png");
	BlockS.load("blocks/skyBlock.png");
	BlockY.load("blocks/yellowBlock.png");
	Blockbl.load("blocks/blackBlock.png");

	//�ؽ�Ʈ �ε�
	text1.loadFont("font/PoplarStd.otf", 32);
	text2.loadFont("font/PoplarStd.otf", 32);
	text3.loadFont("font/PoplarStd.otf", 32);
	text4.loadFont("font/PoplarStd.otf", 128);
	text5.loadFont("font/PoplarStd.otf", 128);

	//�ʱ� ��� ����
	curBlock = (unsigned)rand() % 7;
	nextBlock = (unsigned)rand() % 7;

	//�ʱ�ȭ
	mapsK = &Map[0][0];
}

//--------------------------------------------------------------
void ofApp::update() {


	if (gameStatus == 1) {
		blockDelete();
		move();
		levelUp();
	}

}

//--------------------------------------------------------------
void ofApp::draw() {
	if (gameStatus == 0) {
		opening.draw(0, 0);
	}

	if (gameStatus == 1) {
		drawMap();
		displayText();

		//�� ����
		if (state == 0) {

			appearBlock();
			blockChoosing();
			block1 = &blocks[curBlock][0][0][0];
			block2 = &blocks[nextBlock][0][0][0];
			state = 1;

		}

		//�� �̵�
		else if (state == 1) {
			displayBlock();
		}

		drawTheStopedBlock();
		showNext();
		collideNot();


		endGame();
	}

	if (gameStatus == 2) {
		text4.drawString("Game Over ", 200, 350);
		text5.drawString("your score is : " + ofToString(score), 50, 550);
	}
}

//�ʱ���
void drawMap() {

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 12; j++) {
			if (Map[i][j] == 1) {

				Mapbrick.draw(j*brickWidth, i * brickHight, brickWidth, brickHight);

			}
		}
	}

	MapImage1.draw(0, 200);
}

//�ؽ�Ʈ ��ġ
void displayText() {

	ofSetColor(ofColor::white);
	text1.drawString("Next", 650, 100);
	text2.drawString("score : " + ofToString(score), 650, 500);
	text2.drawString("Level : " + ofToString(level), 650, 400);

}
//��� ����
void blockChoosing() {

	curBlock = nextBlock;
	nextBlock = (unsigned)rand() % 7;
}

//��� ����
void appearBlock() {
	xPos = 5;
	yPos = 0;
}

//�� ȭ�鿡 ���
int displayBlock() {

	int i = 0;
	int j = 0;
	int sum = 0;

	for (j = 0; j < 4; j++) {
		for (i = 0; i < 4; i++) {



			sum = i + 4 * j;

			if (*(block1 + sum) == 1) {
				Map[yPos + j][xPos + i] = 2;
			}

			else {

				for (int j = 0; j < 20; j++) {

					for (int i = 1; i < 11; i++) {

						//������ ���� ����

						if (Map[j][i] == 2) {

							if (Map[j + 1][i] == 3 || Map[j + 1][i] == 1) {
								// 3���� �ٲ�
								for (j = 0; j < 4; j++) {
									for (i = 0; i < 4; i++) {

										sum = i + 4 * j;

										if (*(block1 + sum) == 1) {
											Map[yPos + j][xPos + i] = 3;
											score += 1;
										}

									}
								}
								state = 0;
								return 0;

							}

							//if �� ����

							else {
								Map[j][i] = 0;
							}
						}
					}
				}

			}



			//���� ���� ���
			for (int j = 0; j < 19; j++) {

				for (int i = 1; i < 11; i++) {

					if (Map[j][i] == 2) {

						switch (curBlock) {
						case 0:
							BlockB.draw(i*brickWidth, j * brickHight, brickWidth, brickHight);
							break;

						case 1:
							BlockG.draw(i*brickWidth, j * brickHight, brickWidth, brickHight);
							break;

						case 2:
							BlockO.draw(i*brickWidth, j * brickHight, brickWidth, brickHight);
							break;

						case 3:
							BlockP.draw(i*brickWidth, j * brickHight, brickWidth, brickHight);
							break;

						case 4:
							BlockR.draw(i*brickWidth, j * brickHight, brickWidth, brickHight);
							break;

						case 5:
							BlockS.draw(i*brickWidth, j * brickHight, brickWidth, brickHight);
							break;

						case 6:
							BlockY.draw(i*brickWidth, j * brickHight, brickWidth, brickHight);
							break;

						}

					}

				}

			}


		}
	}

	return 0;
}


//������ ��� ȸ������ ǥ��
void drawTheStopedBlock() {

	for (int j = 0; j < 20; j++) {
		for (int i = 0; i< 12; i++) {


			if (Map[j][i] == 3) {

				Blockbl.draw(i*brickWidth, j * brickHight, brickWidth, brickHight);

			}
		}
	}


}

//�׿��� ��� ��� ����
void blockDelete() {

	int i;
	int j;
	int count = 0;
	for (i = 0; i < 20; i++) {

		for (j = 1; j < 11; j++) {

			maps = &Map[i][j];
			if (*maps != 3) {
				break;
			}

			if (j == 10) {

				if (*maps == 3) {
					maps = &Map[i][1];
					for (int k = 0; k < 10; k++) {
						*maps = 0;


						for (int a = 1; a < i; a++) {
							if (*(maps - 12 * a) != 2 && *(maps - 12 * (a - 1)) != 2) {
								*(maps - 12 * (a - 1)) = *(maps - 12 * (a));
							}

						}

						maps += 1;
					}


				}

				score += 10;
			}


		}


	}

}

//���� ���� �� �����̵忡 ǥ��
void showNext() {

	int sum;



	for (int j = 0; j < 4; j++) {

		for (int i = 0; i < 4; i++) {

			sum = i + 4 * j;

			if (*(block2 + sum) == 1) {

				switch (nextBlock) {
				case 0:
					BlockB.draw((i + 17)*brickWidth, (j + 2) * brickHight, brickWidth, brickHight);
					break;

				case 1:
					BlockG.draw((i + 17)*brickWidth, (j + 2) * brickHight, brickWidth, brickHight);
					break;

				case 2:
					BlockO.draw((i + 17)*brickWidth, (j + 2) * brickHight, brickWidth, brickHight);
					break;

				case 3:
					BlockP.draw((i + 17)*brickWidth, (j + 2) * brickHight, brickWidth, brickHight);
					break;

				case 4:
					BlockR.draw((i + 17)*brickWidth, (j + 2) * brickHight, brickWidth, brickHight);
					break;

				case 5:
					BlockS.draw((i + 17)*brickWidth, (j + 2) * brickHight, brickWidth, brickHight);
					break;

				case 6:
					BlockY.draw((i + 17)*brickWidth, (j + 2) * brickHight, brickWidth, brickHight);
					break;

				}

			}

		}

	}
}


//�Ʒ��� �̵�
void move() {
	if (level == 1) {
		if (ofGetFrameNum() % 30 == 0) {
			yPos += 1;
		}

	}

	if (level == 2) {
		if (ofGetFrameNum() % 20 == 0) {
			yPos += 1;
		}

	}

	if (level == 3) {
		if (ofGetFrameNum() % 15 == 0) {
			yPos += 1;
		}

	}

	if (level >= 4) {
		if (ofGetFrameNum() % 10 == 0) {
			yPos += 1;
		}

	}

}
//���̵� ����
void levelUp() {
	if (score >= 0 && score < 100) {
		level = 1;
	}

	if (score >= 100 && score < 200) {
		level = 2;
	}

	if (score >= 200 && score < 300) {
		level = 3;
	}

	if (score >= 300) {
		level = 4;
	}

}


//���� �浹���� �ʰ� ����
void collideNot() {

	for (int i = 0; i < 20; i++) {
		if (Map[i][0] == 2) {
			xPos += 1;
			Map[i][0] = 1;
		}


		if (Map[i][11] == 2) {
			xPos -= 1;
			Map[i][11] = 1;

		}
	}

}


void endGame() {

	for (int i = 0; i < 5; i++) {
		if (Map[2][xPos+ i] == 3) {
			gameStatus = 2;
		}
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {



	if (gameStatus == 1) {
		if (key == 'w') {
			rotation += 1;

			if (rotation >= 4) {
				rotation = 0;
			}

			block1 = &blocks[curBlock][rotation][0][0];
		}

		else if (key == 'a') {

			xPos -= 1;


		}

		else if (key == 's') {
			yPos += 1;
		}

		else if (key == 'd') {
			xPos += 1;
		}

		else if (key == ' ') {

		}
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

	if (gameStatus == 0) {

		gameStatus = 1;

	}

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}

