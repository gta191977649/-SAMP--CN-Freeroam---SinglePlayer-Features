/*
	Single Vigilante Sub Missions Port To SAMP
    By Episodes

*/

//==================================================
//		    -------	[ȫ�ֺ궨��] -------
//==================================================

#define SINGLE_VIGILANTE 4 //����ID (��Ҫ)


#include <YSI\y_hooks>
#include <zcmd>
#include <sscanf>
//�����궨��
#define HOLDING(%0) \
	((newkeys & (%0)) == (%0))
#define PRESSED(%0) \
	(((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))

#define COLOR_CRI 0xFF0000FF
#define COLOR_NORMAL 0xFFFFFFFF
#define VIGILANTE_INTERGRAL 1000 //ʱ�������ٶ�
//new VIGILANTE_TIMER; //ȫ��ʱ��


//����ȫ��ʱ��
hook OnFilterScriptInit()
{
	SetTimer("VIGILANTE_OnTimeTick",VIGILANTE_INTERGRAL,true);
	print("[SINGLE_VIGILANTE]ȫ��ʱ���Ѿ�����");
	return 1;
}
/*
command(ptest, playerid, params[])
{
	SetPlayerWantedLevel(playerid,3);
}

*/
//ȫ��ʱ���¼�
forward VIGILANTE_OnTimeTick();
public VIGILANTE_OnTimeTick()
{
	for (new i = 0; i < MAX_PLAYERS; i++)
	{
		if(Player[i][PlayerStatus] == SINGLE_VIGILANTE)//�������Ǿ���
		{
			VIGILANTE_MarkCriminalForPlayer(i,true);
		
		}
		else
		{
			VIGILANTE_MarkCriminalForPlayer(i,false);
		}
	}
}
hook OnPlayerStateChange(playerid, newstate, oldstate)
{
    if(oldstate == PLAYER_STATE_ONFOOT && newstate == PLAYER_STATE_DRIVER) 
    {
        new vehicleid = GetPlayerVehicleID(playerid);
		if(GetVehicleModel(vehicleid) == 427 || GetVehicleModel(vehicleid) == 523 || GetVehicleModel(vehicleid) == 596 || GetVehicleModel(vehicleid) == 597 || GetVehicleModel(vehicleid) == 598 || GetVehicleModel(vehicleid) == 599) 
		{
			if(Player[playerid][PlayerStatus] != SINGLE_VIGILANTE) SG_Textbox(playerid,"Prees 2 to start the Vigilante Mission.",3000);//SG_Textbox(playerid,"Press 2 to start Pizza Boy Missions.",3000);
		}
    }
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{

	new vehicleid = GetPlayerVehicleID(playerid);
	if(GetVehicleModel(vehicleid) != 599) return 1;
	//if(Player[playerid][PlayerStatus] != STATUS_NORMAL) return 1;
	
	if (HOLDING( KEY_SUBMISSION))
	{
		if (Player[playerid][PlayerStatus] == SINGLE_VIGILANTE)
		{
			VIGILANTE_InitMissionForPlayer(playerid,false);
			return 1;
		}
		if(Player[playerid][PlayerStatus] == STATUS_NORMAL)
		{
			VIGILANTE_InitMissionForPlayer(playerid,true);
			return 1;
		}		 
	}
	
	//if(Player[playerid][PlayerStatus] != SINGLE_VIGILANTE) return 1;//�ж�����Ƿ���������
	

	return 1;
}

//��������ģʽ
VIGILANTE_InitMissionForPlayer(playerid,type)
{
	switch(type)
	{
		case true:
		{
			Player[playerid][PlayerStatus] = SINGLE_VIGILANTE;
			SG_Sub(playerid,"Find and arrest ~r~criminals~w~.",5000);
		}
		case false:
		{
			Player[playerid][PlayerStatus] = STATUS_NORMAL;
			SG_Sub(playerid,"~r~You have left the vigilante Mission.",5000);
		}
	
	}
	return 1;
}
//����ﷸ���
VIGILANTE_MarkCriminalForPlayer(playerid,type)
{
	switch(type)
	{
		case true:
		{
			//ѭ��ȫ�����
			for(new i = 0 ; i < MAX_PLAYERS ; i ++)
			{
				if(IsPlayerConnected(i))
				{
					if(GetPlayerWantedLevel(i) > 0) MarkPlayerIcon(playerid,i,COLOR_CRI);
				
				}
			}
		
		}
		case false:
		{
					//ѭ��ȫ�����
			for(new i = 0 ; i < MAX_PLAYERS ; i ++)
			{
				if(IsPlayerConnected(i))
				{
					if(GetPlayerWantedLevel(i) > 0) MarkPlayerIcon(playerid,i,COLOR_NORMAL);
				
				}
			}
		
		}
	}
}

forward MarkPlayerIcon(playerid,maker,color);
public MarkPlayerIcon(playerid,maker,color)
{
	SetPlayerMarkerForPlayer(playerid,maker,color);
}

hook OnPlayerDeath(playerid, killerid, reason)
{
	if(Player[killerid][PlayerStatus] != SINGLE_VIGILANTE)
	{
		new temlevel =GetPlayerWantedLevel(killerid);
		if(GetPlayerWantedLevel(killerid) < 6)	SetPlayerWantedLevel(killerid,temlevel++);	
	}
	if(Player[killerid][PlayerStatus] == SINGLE_VIGILANTE)
	{
		new PLevel = GetPlayerWantedLevel(playerid);
		switch (PLevel)
		{
			case 0:
			{
				
			
			}
			case 1:
			{
			
			}
			case 2:
			{
			
			}
			case 3:
			{
			
			}
			case 4:
			{
			
			}
			case 5:
			{
			
			}
			case 6:
			{
			
			}
			default:
			{
			
			}
		
		}
	
	}
	return 1;
}