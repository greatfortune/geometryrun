#include "Bullet.h"


Status BulletLoad()
{
	// ========================
	// �ӵ�
	// ========================
	AEGfxMeshStart();
	AEGfxTriAdd(
		-1.0f, -1.0f, COLOR_DEFAULT, 0.0f, 1.0f,
		1.0f, -1.0f, COLOR_DEFAULT, 1.0f, 1.0f,
		-1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);
	AEGfxTriAdd(
		1.0f, -1.0f, COLOR_DEFAULT, 1.0f, 1.0f,
		1.0f, 1.0f, COLOR_DEFAULT, 1.0f, 0.0f,
		-1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);
	CreateGameObjBase(OTYPE_BULLET, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/bullet.png"), theBaseList);
	return OK;
}

Status BulletStart()
{
	Vector2DSet(&Velocity_Bullet, 400.0f, 0.0f);
	return OK;
}

Status BulletUpdate(GameObj* pInst)
{
	pInst->posCurr.x += pInst->velCurr.x * frameTime;
	pInst->posCurr.y += pInst->velCurr.y * frameTime;
	if ((pInst->posCurr.x < winMinX) || (pInst->posCurr.x > winMaxX) || (pInst->posCurr.y < winMinY) || (pInst->posCurr.y > winMaxY))
		GameObjDelete(pInst);
	return OK;
}

Status BulletCollision(insNode* pinsNode)
{
	GameObj* pInstOther = &(pinsNode->gameobj);

	switch (pInstOther->pObject->type)
	{
		//BULLET VS MONSTER/AIMONSTER
		case OTYPE_MONSTER:
		case OTYPE_AIMONSTER:
		{
			// ��ײ���
			if (StaticCircleToStaticCircle(&(pInstForCollisionDetect->posCurr), pInstForCollisionDetect->scale, &(pInstOther->posCurr), pInstOther->scale))
			{
				// ײ��Monster�������ӵ���MONSTER
				GameObjDelete(pInstOther);
				GameObjDelete(pInstForCollisionDetect);
			}
			break;//BULLET VS MONSTER/AIMONSTER����
		}

		//BULLET VS BLOCK
		case OTYPE_BLOCK:
		{
			// ��ײ���
			if (StaticCircleToStaticCircle(&(pInstForCollisionDetect->posCurr), pInstForCollisionDetect->scale, &(pInstOther->posCurr), pInstOther->scale))
			{
				// ײ��BLOCK������BULLET
				GameObjDelete(pInstForCollisionDetect);
			}
			break;//BULLET VS BLOCK����
		}
		case OTYPE_BOSS2:
		{
			// ��ײ���
			if (StaticCircleToStaticCircle(&(pInstForCollisionDetect->posCurr), pInstForCollisionDetect->scale, &(pInstOther->posCurr), pInstOther->scale))
			{
				// ײ��BOSS2, ��Ѫ,����BULLET
				Boss2GetHurt();
				GameObjDelete(pInstForCollisionDetect);
			}
		}
	}
	return OK;
}
