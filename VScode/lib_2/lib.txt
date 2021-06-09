#ifndef lab_H
#define lab_H

int mystrlen(const char* str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}

char * mystrcat(char * str1, char* str2)
{
	int num = mystrlen(str1), num2 = mystrlen(str2);
	for (int i = num,j=0; i < num + num2 + 1; i++,j++)
	{
		str1[i] = str2[j];
	}
	return str1;
}

char * mystrcpy(char* str1, char* str2)
{
	int num2 = mystrlen(str2);
	for (int i = 0, j = 0; i < num2 + 1; i++, j++)
	{
		str1[i] = str2[j];
	}
	return str1;
}

char* mystrchr(char* str, char s)
{
	int num2 = mystrlen(str), k=0;
	for (int i = 0; i < num2; i++)
	{
		if (str[i] == s)
		{
			k++;
			return (str+i);
		}
	}
	if (k != 0)
		return NULL;
}

char* mystrstr(char* str1, char* str2)
{
	int num2 = mystrlen(str2), num1 = mystrlen(str1), f=0;
	for (int i = 0; i < num1-1; i++)
	{
		if (str1[i] == str2[0])
		{
			for (int j = i; j < num2; j++)
			{
				if (str1[j] == str2[j])
					f = 0; continue;
				if (str1[j] != str2[j])
					f = 1; break;
			}
			if (f == 0)
				return (str1 + i);
			else
				return NULL;
		}
	}
}
#endif