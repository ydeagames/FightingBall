#pragma once
#include "GameObject.h"

// �萔�̒�` ==============================================================

// <�v���C���[>
#define PLAYER_VEL 4.f		// �v���C���[�̑��x
// <�G>
#define ENEMY_VEL 2			// �G�̑��x
// <�e>
#define BULLET_VEL 10		// �G�̑��x

// �񋓌^�̒�` ============================================================

// <���> --------------------------------------------------------------

typedef enum
{
	TYPE_UNKNOWN = 0,
	TYPE_PLAYER,
	TYPE_PLAYER_BULLET,
	TYPE_ENEMY1,
	TYPE_ENEMY2
} ObjectType;

// �֐��̐錾 ==============================================================

// <<�G�I�u�W�F�N�g>> ----------------------------------------------

// <�G�I�u�W�F�N�g�쐬>
GameObject GameObject_Enemy_Create(void);

// <�G�I�u�W�F�N�g���W�f�t�H���g>
void GameObject_Enemy_SetPosDefault(GameObject* obj, GameObject* field);

// <�G�I�u�W�F�N�g�ړ��f�t�H���g>
void GameObject_Enemy_SetVelDefault(GameObject* obj);

// <<�v���C���[�I�u�W�F�N�g>> ----------------------------------------------

// <�v���C���[�I�u�W�F�N�g�쐬>
GameObject GameObject_Player_Create(void);

// <�v���C���[�I�u�W�F�N�g���WY�f�t�H���g>
void GameObject_Player_SetPosYDefault(GameObject* obj, GameObject* field);

// <<�e�I�u�W�F�N�g>> ----------------------------------------------

// <�e�I�u�W�F�N�g�쐬>
GameObject GameObject_Bullet_Create(void);

// <�e�I�u�W�F�N�g���W�f�t�H���g>
void GameObject_Bullet_SetPosDefault(GameObject* obj, GameObject* player);

// <�e�I�u�W�F�N�g�ړ��f�t�H���g>
void GameObject_Bullet_SetVelDefault(GameObject* obj, int num = 0, int total = 1);

// <�e�I�u�W�F�N�g�T�C�Y�ύX>
void GameObject_Bullet_SetSize(GameObject* obj, float scale);

// <�e�I�u�W�F�N�g����>
void GameObject_Bullet_Grow(GameObject* obj);