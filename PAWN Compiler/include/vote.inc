// ͶƱģ�� ͶƱ ����һ����
// v 1.0 ���� /voteban /votekick
// BY: GTAYY

#if defined _vote_inc
#endinput
#endif
#define _vote_inc

#include "vote_h"


stock vote:OnGameModeInit()
{
	print("[���] ͶƱban,kick�ɹ�����!");
	SendClientMessageToAll(0xFF0000AA,"[���] ͶƱban,kick�ɹ�����!");
}

stock vote:OnGameModeExit()
{
	print("[���] ͶƱban,kick�ɹ�ж��!");
	SendClientMessageToAll(0xFF0000AA,"[���] ͶƱban,kick�ɹ�ж��!");
}

stock vote:OnPlayerConnect(playerid)
{
    votebannum[playerid] = 0;
    votekicknum[playerid] = 0;
	allvote++;
}

stock vote:OnPlayerDisconnect(playerid)
{

    for(new i = 0; i < MAX_PLAYERS;i++)
    {
    	votekflag[playerid][i] = false;
     	votebflag[playerid][i] = false;
      	if(votebannum[i] != 0) votebannum[i]--;
        if(votekicknum[i] != 0) votekicknum[i]--;
    }
	allvote--;
}

//ͶƱ
COMMAND:votekick(playerid,params[])
{
	new id;
	new sreason[64];
	new pname[MAX_PLAYER_NAME],gname[MAX_PLAYER_NAME];
	new string[128];
	if(sscanf(params,"us[64]",id,sreason))
	{
	    SendClientMessage(playerid, 0xFF0000AA, "�÷�: \"/votekick <�������/���> <ԭ��>\"");
	}else if(id == INVALID_PLAYER_ID)
	{
	    SendClientMessage(playerid, 0xFF0000AA, "��Ч�����ID!");
	}else if(id == playerid)
	{
	    SendClientMessage(playerid, 0xFF0000AA, "�㲻���Զ��Լ�ʹ��!");
	}else if(IsPlayerNPC(id))
	{
	    SendClientMessage(playerid, 0xFF0000AA, "�㲻���Զ�NPCʹ��!");
	}else
	{
		GetPlayerName(id,gname,sizeof(gname));
		GetPlayerName(playerid,pname,sizeof(pname));
		if(!votekflag[playerid][id])
		{
			votekicknum[id]++;
			votekflag[playerid][id] = true;
	  		if(votekicknum[id] == (allvote/2))
	    	{
				format(string,sizeof(string),"���ڴ󲿷��˵ľ��� %s ���߳�������",gname);
				SendClientMessageToAll(0xFF0000AA,string);
	  			Kick(id);
		    }else
		    {
				format(string,sizeof(string),"%s ����ͶƱ�߳� %s ��ǰ���� %d Ʊ ԭ��:%s",pname,gname,(allvote/2)-votekicknum[id],sreason);
				SendClientMessageToAll(0xFF0000AA,string);
	   		}
		}else
		{
		    SendClientMessage(playerid, 0xFF0000AA, "�㲻���ظ�ͶƱŶ!");
			format(string,sizeof(string),"%s ����ͶƱ�߳� %s ��ǰ���� %d Ʊ ԭ��:%s",pname,gname,(allvote/2)-votekicknum[id],sreason);
			SendClientMessageToAll(0xFF0000AA,string);
		}
	}
	return 1;
}

COMMAND:voteban(playerid,params[])
{
	new id;
	new sreason[64];
	new pname[MAX_PLAYER_NAME],gname[MAX_PLAYER_NAME];
	new string[128];
	if(sscanf(params,"us[64]",id,sreason))
	{
	    SendClientMessage(playerid, 0xFF0000AA, "�÷�: \"/voteban <�������/���> <ԭ��>\"");
	}else if(id == INVALID_PLAYER_ID)
	{
	    SendClientMessage(playerid, 0xFF0000AA, "��Ч�����ID!");
	}else if(id == playerid)
	{
	    SendClientMessage(playerid, 0xFF0000AA, "�㲻���Զ��Լ�ʹ��!");
	}else if(IsPlayerNPC(id))
	{
	    SendClientMessage(playerid, 0xFF0000AA, "�㲻���Զ�NPCʹ��!");
	}else
	{
		GetPlayerName(id,gname,sizeof(gname));
		GetPlayerName(playerid,pname,sizeof(pname));
		if(!votebflag[playerid][id])
		{
	 	    votebannum[id]++;
	 	    votebflag[playerid][id] = true;
	 	    if(votebannum[id] == (allvote/2))
	 	    {
				format(string,sizeof(string),"���ڴ󲿷��˵ľ��� %s ����ֹ���������",gname);
				SendClientMessageToAll(0xFF0000AA,string);
		    	Ban(id);
	 	    }else
	 	    {
				format(string,sizeof(string),"%s ����ͶƱ��� %s ��ǰ���� %d Ʊ ԭ��:%s",pname,gname,(allvote/2)-votebannum[id],sreason);
				SendClientMessageToAll(0xFF0000AA,string);
			}
		}else
		{
		    SendClientMessage(playerid, 0xFF0000AA, "�㲻���ظ�ͶƱŶ!");
			format(string,sizeof(string),"%s ����ͶƱ��� %s ��ǰ���� %d Ʊ ԭ��:%s",pname,gname,(allvote/2)-votebannum[id],sreason);
			SendClientMessageToAll(0xFF0000AA,string);
		}
	}
	return 1;
}