//�ַ���תɫ�������� BY GTAYY
#include <a_samp>

stock strcolorcn(const string[])
{
    new color[][][] =//�������Ӷ������ɫ��ѯ�ַ�
    {
        {"*��ɫ","{F81414}"},
        {"*��ɫ","{6EF83C}"},
        {"*��ɫ","{0049FF}"},
        {"*��ɫ","{FFFFFF}"},
        {"*��ɫ","{FFFA00}"},
        {"*��ɫ","{FF00F5}"},
        {"*����ɫ","{00CDFF}"},
        {"*����ɫ","{00FFE6}"}

        //��������������    //��������� {"*red","{0049FF}"}
    };
	new tmp[256];
	new address;
	format(tmp,sizeof(tmp),"%s",string);
	for(new i = 0; i < sizeof(color); i++)
	{
	    while((address = strfind(tmp, color[i][0], false)) != -1)
	    {
	        strdel(tmp,address,address+strlen(color[i][0]));
	        strins(tmp,color[i][1],address);
	    }
	}
	return tmp;
}