#include "DxLib.h"
#include "SceneMain.h"

SceneMain::SceneMain()
{
	m_hPlayerGraphic = -1;
	m_hShotGraphic = -1;
}
SceneMain::~SceneMain()
{

}

// ������
void SceneMain::init()
{
	m_hPlayerGraphic = LoadGraph("data/player.bmp");
	m_hShotGraphic = LoadGraph("data/shot.bmp");

	m_player.setHandle(m_hPlayerGraphic);
	m_player.init();
	m_player.setMain(this);

	for (auto& shot : m_shot)
	{
		shot.setHandle(m_hShotGraphic);
	}
}

// �I������
void SceneMain::end()
{
	DeleteGraph(m_hPlayerGraphic);
	DeleteGraph(m_hShotGraphic);
}

// ���t���[���̏���
void SceneMain::update()
{
	m_player.update();
	for (auto& shot : m_shot)
	{
		shot.update();
	}
}

// ���t���[���̕`��
void SceneMain::draw()
{
	m_player.draw();

	for (auto& shot : m_shot)
	{
		shot.draw();
	}

	//
	int shotNum = 0;
	for (auto& shot : m_shot)
	{
		if (shot.isExist())shotNum++;
	}
	DrawFormatString(0, 0, GetColor(255, 255, 255), "�e�̐�:%d", shotNum);
}

bool SceneMain::createShot(Vec2 pos)
{
	for (auto& shot : m_shot)
	{
		if (shot.isExist())continue;

		shot.start(pos);
		return true;
	}
	return false;
}