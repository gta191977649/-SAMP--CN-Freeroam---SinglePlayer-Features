//==========================public OPU===============================//

public AntiTrackTest(playerid)
{
	P[playerid][iCurVW] = GetPlayerVirtualWorld(playerid);
	if(P[playerid][iCurrentVW] != P[playerid][iCurVW])
	    if(P[playerid][UsedCmdToChangeVW] == false)
	    {
	        new i[256],pn[256];
	        GetPlayerName(playerid,pn,sizeof(pn));
	        format(i,sizeof(i),"[ף��]��� %s ��Ϊʹ��������׷��������Ҷ��õ��˽���!Taſ����!",pn);
	        SetPlayerHealth(playerid,0.0);
	        SendClientMessageToAll(COLOR_RED,i);
	    	P[playerid][iCurrentVW] = P[playerid][iCurVW];
		}
		else
		{
	        SendClientMessage(playerid,COLOR_RED,"�л�����");
			P[playerid][UsedCmdToChangeVW] = false;
	    	P[playerid][iCurrentVW] = P[playerid][iCurVW];
  		}
	return 1;
}