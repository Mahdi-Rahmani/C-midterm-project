//  Name:                Mahdi Rahmani
// shomare daneshjooee:  9731701
// algoritm2 (baraye ghesmate asli)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int password[13][12];
int guess_index=0; 
int two_index;
int pass_length;
int repeat_verify;
int repeat_find;
int guess_previous[11];
// baraye neshan dadane hads
void show_guess(int guess[2][pass_length])
{
	guess_index++;
	int i_index;
	printf("GUESS %d:",guess_index);
	for(i_index=0;i_index<pass_length;i_index++)
	{
		if(guess[0][i_index]==10)
		{
			printf("*");
		}
		else if(guess[0][i_index]==11)
		{
			printf("#");
		}
		else
		{
			printf("%d",guess[0][i_index]);
		}
	}
	printf("\n");
}
// baraye gereftane reaction karbar
void first_guess_react(int guess[2][pass_length])
{
	int i_index,j_index,f_index,foo;
	int rand_num;
	char react_get[pass_length+1];
	//ebteda 1 hadse avalie mizanim
	for(i_index=0;i_index<pass_length;i_index++)
	{
		rand_num=rand()%12;
		guess[0][i_index]=rand_num;
		//hame adad motemayez bashand
		for(j_index=0;j_index<i_index;j_index++)
		{
			foo=1;
			while(guess[0][i_index]==guess[0][j_index]||foo==0)
			{
				foo=1;
				rand_num=rand()%12;
				guess[0][i_index]=rand_num;
				for(f_index=0;f_index<j_index;f_index++)
				{
					if(guess[0][i_index]==guess[0][f_index])
						foo=0;	
				}
			}
		}
	}
	//namayshe hadse avalie
	show_guess(guess);
	// reaction aval bayad az shirfarhad daryaft shavad
	scanf("%s",react_get);
	for(i_index=0;i_index<pass_length;i_index++)
	{
		guess[1][i_index]=react_get[i_index]-48;
	}
	
	for(i_index=0;i_index<pass_length;i_index++)
	{
		if(guess[1][i_index]==2)
		{
			password[1][guess[0][i_index]]=2;
			two_index++;
		}else if(guess[1][i_index]==0)
		{
			password[1][guess[0][i_index]]=3;
		}
		else
		{
			password[1][guess[0][i_index]]=1;
			password[2][guess[0][i_index]]++;
			f_index=password[2][guess[0][i_index]];
			password[2+f_index][guess[0][i_index]]=i_index;
		}
	}
}
//barresi dade ha baraye guess marhale bad
void modify(int guess[2][pass_length],int guess_modified[2][pass_length])
{
	int i_index,j_index,f_index;
	int rand_num;
	int rand_different[pass_length];
	// por kardane guess_test ba eslahate lazem tebghe reacte karabar
	for(i_index=0;i_index<pass_length;i_index++)
	{
		guess_modified[0][i_index]=0;
		guess_modified[1][i_index]=0;	
	}
	int on1;
	for(i_index=0;i_index<pass_length;i_index++)
	{
		//sabet negah dashtane adad ba( react 2)
		if(guess[1][i_index]==2)
		{
			guess_modified[0][i_index]=guess[0][i_index];
			guess_modified[1][i_index]=guess[1][i_index];		
		}
		if(guess[1][i_index]==1&&password[1][guess[0][i_index]]!=2)
		{
			//baraye jabeja kardane adadi ke (react 1) dashte
			for(j_index=pass_length-1;j_index>=0;j_index--)
			{
				on1=0;
				//avalan jaye ooni ke react 2 dare nabayad bere
				if(guess[1][j_index]!=2)
				{
					// dovoman jaye ghablish nabayad bere pas hame khoone haee ke ghablan bude check mishe
					for(f_index=password[2][guess[0][i_index]];f_index>0;f_index--)
					{
						if(j_index!=password[f_index+2][guess[0][i_index]])
						{
							on1++;
						}
					}
					//agar khune jadidi ke mikhad bere tush tekrari nabud:
					if(on1==password[2][guess[0][i_index]])
					{
						// havaseman bashad jaye baghie adadi ke bad az modify kardan, react 1 dashtan va jabeja shodan ya adadi ke react 2 dashtan gharar nagire
						if(guess_modified[1][j_index]==0)
						{
							guess_modified[0][j_index]=guess[0][i_index];
							guess_modified[1][j_index]=guess[1][i_index];
							guess[0][i_index]=0;
							guess[1][i_index]=0;
						}
					}
				}
			}
		}
	}
	int full_index=0;
	//baraye inke zoodtar be natije bereim say mikonim hichvaght dar hadseman adade tekrary nabashe. pas momkene be jaee beresim ke hame adad reactdar shode and vali chon dakhele ramz adade tekrari ast be javab nareside bashim.
	for(i_index=0;i_index<12;i_index++)
	{
		if(password[1][i_index]!=0)
		{
			full_index++;
		}
	}
	int on2=0;
	int	x=0;
	int zero_index=0,n,accept=0;
	//jaygozin kardane adadi ke (react 0) dashtan ba adade randome jadid
	for(i_index=0;i_index<pass_length;i_index++)
	{ 
		int break_command=0;
		accept=1;

		if(guess_modified[1][i_index]==0)
		{
			rand_num=rand()%12;
			//agar hame adad react dashtan pas adade tekrary darim
			if(full_index==12)
			{
				on2++;
				// az beine oonaee ke darim dobare yeseriha ro entekhab mikonim
				for(j_index=repeat_find;j_index<pass_length;j_index++)
				{
					if(guess_modified[1][j_index]==2)
					{
						guess_modified[0][i_index]=guess_modified[0][j_index];
						guess[0][i_index]=guess_modified[0][j_index];
						repeat_find=j_index+1;
						break;
					}
				}
				int two=0;
				int foo;	
				if(pass_length==repeat_find)
					repeat_find=0;
			}
			else// agar hanuz hame adad react nadashtan havaseman bashe ke az adade react dar ya hadshaye tekrary estefade nakonim
			{
				zero_index=0;
				int foo;
				int break_command_array[12]={0};
				for(j_index=0;j_index<x-1;j_index++)
				{
					//brarye azbein bordane didgit haye rand tekrary
					if(rand_num==rand_different[j_index])
					{
						accept++;
					}
				}
				while(password[1][rand_num]==3||password[1][rand_num]==1||password[1][rand_num]==2||accept!=0)
				{
					rand_num=rand()%12;
					rand_different[x]=rand_num;
					break_command_array[rand_num]++;
					accept=0;
					for(j_index=0;j_index<x;j_index++)
					{
						//brarye azbein bordane didgit haye rand tekrary
						if(rand_num==rand_different[j_index])
						{
							accept++;
						}
					}
					break_command=0;
					//agar hich adad motemayezi yaft nashod break bede
					for(foo=0;foo<12;foo++)
					{
						if(break_command_array[foo]>1)
							break_command++;
					}
					if(break_command==12)
					{
						on2++;
						// az beine oonaee ke darim dobare yeseriha ro entekhab mikonim
						for(j_index=0;j_index<pass_length;j_index++)
						{
							if(guess_modified[1][j_index]==2)
							{
								rand_num=guess_modified[0][j_index];
								break;
							}
						}
						break;
					}

				}
				guess_modified[0][i_index]=rand_num;
				guess[0][i_index]=rand_num;
			}
			if(break_command!=12)
				x++;			
		}
	}
	repeat_verify=on2;
}
//dar in tabe hamzaman be gereftane reaction karbar motabeghate on ba ghabli ha ro ham check mikone
void get_react(int guess[2][pass_length],int guess_modified[2][pass_length])
{
	int adapt;
	char react_get[pass_length+1];
	int i_index;
	do{
		adapt=0;
		//gerefteane reaction
		scanf("%s",react_get);
		for(i_index=0;i_index<pass_length;i_index++)
		{
			guess[1][i_index]=react_get[i_index]-48;
		}
		//hala check mikone aya ma alan be marhale ee residim  ke ramzemun adade tekrary dare ya na
		if(repeat_verify>0)
		{
			for(i_index=0;i_index<pass_length;i_index++)
			{
				if(guess_modified[1][i_index]==2)
				{
					if(guess[1][i_index]!=2)
						adapt++;
				}
				if(guess[1][i_index]==0)
				{
					if(password[1][guess[0][i_index]]==1||password[1][guess[0][i_index]]==2)
						adapt++;
				}
			}
		}
		else
		{
			//check kardane ghalat ya dorost budan react
			for(i_index=0;i_index<pass_length;i_index++)
			{
				if(guess[1][i_index]==1)
				{
					if(password[1][guess[0][i_index]]==2)
						adapt++;
				}
				if(guess[1][i_index]==0)
				{
					if(password[1][guess[0][i_index]]==1||password[1][guess[0][i_index]]==2)
						adapt++;
				}
			}
		}			
		if(adapt!=0)
		{
			printf("The guidance was wrong. Be more careful and helpful.\n");
		}
	}while(adapt!=0);
}
// copy kardane dade ha dar araye password
void cpy_in_pass(int guess[2][pass_length],int guess_modified[2][pass_length])
{
	int i_index,f_index;
	for(i_index=0;i_index<pass_length;i_index++)
	{
		guess[0][i_index]=guess_modified[0][i_index];
		if(guess[1][i_index]==2)
		{
			password[1][guess[0][i_index]]=2;
		}else if(guess[1][i_index]==0)
		{
			password[1][guess[0][i_index]]=3;
		}
		else
		{
			if(password[1][guess[0][i_index]]!=2)
			{
				password[1][guess[0][i_index]]=1;
				password[2][guess[0][i_index]]++;
				f_index=password[2][guess[0][i_index]];
				password[2+f_index][guess[0][i_index]]=i_index;
			}
		}
	}
}
int main() {
	time_t t=time(NULL);
	srand(t);
	printf("please enter the length of the password:\n");
	scanf("%d",&pass_length);
	int guess[2][pass_length];
	int guess_modified[2][pass_length];
	first_guess_react(guess);
	int i_index;
	int verify=1;
	if(two_index==pass_length)
		verify=0;
	while(verify)
	{
		modify(guess, guess_modified);
		show_guess(guess_modified);
		get_react(guess,guess_modified);
		cpy_in_pass(guess,guess_modified);
		
		two_index=0;
		for(i_index=0;i_index<pass_length;i_index++)
		{
			if(guess[1][i_index]==2)
			{
				two_index++;
			}
		}
		if(two_index==pass_length)
			verify=0;
		if(guess_index==10)
		{
			printf("Ruuuuun!!!");
			return 0;
		}
	}
	return 0;
}
