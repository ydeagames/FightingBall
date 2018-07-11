#include "ScenePlay.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "GameMain.h"
#include "GameObjects.h"
#include "GameController.h"
#include "GameResource.h"
#include "GameUtils.h"



// 定数の定義 ==============================================================

#define NUM_PLAYERS 2

// グローバル変数の定義 ====================================================

int g_count;

GameResource g_resources;

GameObject g_field;
GameObject g_players[NUM_PLAYERS];
GameController g_player_ctrls[NUM_PLAYERS];




// 関数の宣言 ==============================================================

void InitializePlay(void);  // ゲームの初期化処理
void UpdatePlay(void);      // ゲームの更新処理
void RenderPlay(void);      // ゲームの描画処理
void FinalizePlay(void);    // ゲームの終了処理




// 関数の定義 ==============================================================

//----------------------------------------------------------------------
//! @brief ゲームの初期化処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void InitializePlay(void)
{
	g_count = 0;

	g_resources = GameResource_Create();

	g_field = GameObject_Field_Create();

	{
		int i;
		for (i = 0; i < NUM_PLAYERS; i++)
		{
			g_players[i] = GameObject_Player_Create();
			// 当たり判定を円に変更
			g_players[i].shape = SHAPE_CIRCLE;
			g_players[i].sprite = GameSprite_Create(GameTexture_Create(g_resources.texture_player, Vec2_Create(), Vec2_Create(32, 32)), 1.5f);
			g_players[i].sprite.offset.y -= 7;
			g_players[i].pos = g_field.pos;

			g_player_ctrls[i] = GameController_Player_Create(&g_players[i], PlayerKeySet_Default_Create());
		}
	}
}



//----------------------------------------------------------------------
//! @brief ゲームの更新処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void UpdatePlay(void)
{
	g_count++;

	{
		if (IsKeyPressed(PAD_INPUT_2))
			RequestScene(SCENE_RESULT);

		{
			int i;
			for (i = 0; i < NUM_PLAYERS; i++)
			{
				GameController_Update(&g_player_ctrls[i]);
				GameController_UpdateControl(&g_player_ctrls[i]);
			}
		}
	}

	{
		int i;
		for (i = 0; i < NUM_PLAYERS; i++)
		{
			GameObject_UpdatePosition(&g_players[i]);
		}
	}

	{
		int i;
		for (i = 0; i < NUM_PLAYERS; i++)
		{
			GameObject_Field_CollisionVertical(&g_field, &g_players[i], CONNECTION_BARRIER, EDGESIDE_INNER);
			GameObject_Field_CollisionHorizontal(&g_field, &g_players[i], CONNECTION_BARRIER, EDGESIDE_INNER);
		}
	}
}




//----------------------------------------------------------------------
//! @brief ゲームの描画処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void RenderPlay(void)
{
	{
		int i;
		for (i = 0; i < NUM_PLAYERS; i++)
		{
			if (GameObject_IsAlive(&g_players[i]))
				GameObject_Render(&g_players[i]);
		}
	}
}



//----------------------------------------------------------------------
//! @brief ゲームの終了処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void FinalizePlay(void)
{
	GameResource_Delete(&g_resources);
}
