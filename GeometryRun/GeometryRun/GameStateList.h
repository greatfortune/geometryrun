#pragma once

/**
 * Project:		GameStateManager
 * File Name:	GameStateList.h
 * Author:		����
 * Date:		2017-4-4
 * Purpose:		��Ϸ״̬��������ҪΪGame Flow��״̬�л�����
 */


 //------------------------------------------------------------------------------
 // Typedef:
 //------------------------------------------------------------------------------

 //------------------------------------------------------------------------------
 // Public Consts:
 //------------------------------------------------------------------------------

 //------------------------------------------------------------------------------
 // Public Structures:
 //------------------------------------------------------------------------------

 //------------------------------------------------------------------------------
 // Public Variables:
 //------------------------------------------------------------------------------
int Previous;
int Current;
int Next;

enum
{
	GS_L1,              // Level1
	GS_L2,              // Level2
	GS_NUM,             // Total Number
	GS_Restart,			// Restart
	GS_Quit				// Quit
};

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------