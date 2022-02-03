//                       name:       Mahdi Rahmani
//         shomare daneshjuee:       9731701
//     tarikh tahvile project:       1399/2/25

#include <stdio.h>
#include <stdlib.h>
int password[13][12];
int guess_index=0; 
int two_index;
int pass_length;
int repeat_verify;
int repeat_find;
int guess_previous[11];
int number;
int different_counter;
int digit_index;
int condition;
int new_guess[12];
int zero_arr[12];

//baraye neshan dadane guess va shomordane guess_index
void show_guess(int guess[2][pass_length])
{
	int i_index;
	
	guess_index++;
	if(guess_index>10)
	{	
		printf("Ruuuuun!!!");
		exit(0);
	}
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
//peida kardane hadse avalie baraye halaty ke nezam dorost hads miznad
void primary_guess_file(int primary_guess[2][pass_length])
{
	int i_index,j_index,flag=0;
	char react_get[pass_length+1];
	int guess_modified[2][pass_length];
	
	for(i_index=0;i_index<pass_length;i_index++)
	{
		if(number<12)
		{
			primary_guess[0][i_index]=number;
			number++;
		}
		else
		{
			for(j_index=flag;j_index<12;j_index++)
			{
				if(password[1][j_index]==3)
				{
					primary_guess[0][i_index]=j_index;
					flag=j_index+1;
					break;
				}
			}
		}
	}	
}
//copy cardane vorudihaye karbar dar araye password baraye hads haye avalie
void cpy_in_pass_primaryguess(int primary_guess[2][pass_length])
{
	int i_index;
	for(i_index=0;i_index<pass_length;i_index++)
	{
		if(primary_guess[1][i_index]==2)
		{
			password[1][primary_guess[0][i_index]]=2;
			password[3][primary_guess[0][i_index]]=i_index;
			two_index++;
		}else if(primary_guess[1][i_index]==0)
		{
			password[1][primary_guess[0][i_index]]=3;
		}
		else
		{
			password[1][primary_guess[0][i_index]]=1;
		}
	}
}
//check kardane inke aya vorudi ba dade haye ghabli hamkhani darad ya na
int adoption_check(int guess_modified[2][pass_length])
{
	int  i_index,adapt=0;
	int	arr_different_value[12]={0};
	int different_counter_new=0;
	//check kardan ba dade haye zakhire shode dar araye password
	for(i_index=0;i_index<pass_length;i_index++)
	{
		if(guess_modified[1][i_index]==2)
		{
			if(password[1][guess_modified[0][i_index]]==3)
				adapt++;
		}
		if(guess_modified[1][i_index]==1)
		{
			if(password[1][guess_modified[0][i_index]]==3)
				adapt++;
			if(password[1][guess_modified[0][i_index]]==2)
			{
				if(password[3][guess_modified[0][i_index]]==i_index)
					adapt++;
			}
		}
		if(guess_modified[1][i_index]==0)
		{
			if(password[1][guess_modified[0][i_index]]==1||password[1][guess_modified[0][i_index]]==2)
				adapt++;
		}
	}
	
	int new_two_index=0;
	for(i_index=0;i_index<pass_length;i_index++)
	{
		if(guess_modified[1][i_index]==2)
		{
			new_two_index++;
		}
	}
	//chek mikone harvaght krbar delesh khast 4 ta 2 nazane
	if(new_two_index==pass_length)
	{
		for(i_index=0;i_index<pass_length;i_index++)
		{
			arr_different_value[guess_modified[0][i_index]]++;
		}
		for(i_index=0;i_index<12;i_index++)
		{
			if(arr_different_value[i_index]!=0)
				different_counter_new++;
		}
		if(condition==1)
		{
			if(different_counter_new!=different_counter)	
				adapt++;
		}
		else
		{
			if(different_counter_new==different_counter)	
				adapt++;
		}
	}
	
	return adapt;
}
//gereftane reaction karbar va hamzaman check karadan entebaghe on ba dade haye ghabli be komake tabe (adoption_check)
void get_react(int guess_modified[2][pass_length])
{
	int i_index,adapt;
	char react_get[pass_length+1];
	
	do{
		adapt=0;
		int dist=0;
		
		scanf("%s",react_get);
		for(i_index=0;i_index<pass_length;i_index++)
		{
			guess_modified[1][i_index]=react_get[i_index]-48;
		}
		adapt=adoption_check(guess_modified);
		if(adapt!=0)
		{
			printf("The guidance was wrong. Be more careful and helpful.\n");
		}
	}while(adapt!=0);
}

//copy cardane vorudihaye karbar dar araye password baraye baghie hadse ha(zamani ke adade dakhele ramz peida shod)
void cpy_in_pass(int guess_modified[2][pass_length])
{
	int i_index;
	for(i_index=0;i_index<pass_length;i_index++)
	{
		if(guess_modified[1][i_index]==2)
		{
			password[1][guess_modified[0][i_index]]=2;
			password[3][guess_modified[0][i_index]]=i_index;
		}
	}
}
//zadane hadse avalie baraye halati ke nezam hads hash be surate randome
void random_guess(int primary_guess[2][pass_length])
{
	int i_index;
	primary_guess[0][0]=number;
	number++;
	for(i_index=1;i_index<pass_length;i_index++)
	{
		primary_guess[0][i_index]=number;
	}
	number++;
}
//be dast avardane adade mojud dar ramz va zakhire bazi az etelaate on zamani ke nezam hadse random mizanad
void information_primary_rand_guess(int guess_modified[2][pass_length],int primary_guess[2][4])
{
	int i_index, none_zero_index=0,foo=0;
	int new_two_index=0,one_index=0;
	static int zero_index=0;
	
	for(i_index=0;i_index<pass_length;i_index++)
	{
		if(primary_guess[1][i_index]==2)
		{
			new_two_index++;
			none_zero_index++;
		}
		if(primary_guess[1][i_index]==1)
		{
			one_index++;
			none_zero_index++;
		}
	}
	// 4 halat vase tedade adde gheire sefr vojud darad:
	//halate1
	if(none_zero_index==1)
	{
		new_guess[digit_index]=primary_guess[0][0];
		zero_arr[zero_index]=primary_guess[0][1];
		zero_index++;
		digit_index++;
		different_counter++;
			
		if(new_two_index==1)
		{
			guess_modified[0][ 0]=primary_guess[0][0];
			guess_modified[1][ 0]=2;
		}
	}
	//halate2
	if(none_zero_index==(pass_length-1))
	{
		different_counter++;	
		new_guess[digit_index]=primary_guess[0][1];
		zero_arr[zero_index]=primary_guess[0][0];
		zero_index++;
		digit_index++;
		
		if(new_two_index==(pass_length-1))
		{
			for(i_index=1;i_index<pass_length;i_index++)
			{
				guess_modified[0][i_index]=primary_guess[0][1];
				guess_modified[1][i_index]=2;
			}
		}
		if(one_index==(pass_length-1))
		{
			guess_modified[0][0]=primary_guess[0][1];
			guess_modified[1][0]=2;
		}
	}
	//halate3	
	if(none_zero_index==pass_length)
	{
		different_counter+=2;;	
		new_guess[digit_index]=primary_guess[0][0];
		digit_index++;
		new_guess[digit_index]=primary_guess[0][1];
		digit_index++;
		
		if(new_two_index==pass_length)
		{
			if(different_counter==2)
				exit(0);
		}
		if(one_index==pass_length)
		{
			guess_modified[0][0]=primary_guess[0][1];
			guess_modified[1][0]=2;
		}
		if(new_two_index==(pass_length-1))
		{
			guess_modified[0][0]=primary_guess[0][0];
			guess_modified[1][0]=2; 
			
		}
	}
	//halate4
	if(none_zero_index==0)
	{
		zero_arr[zero_index]=primary_guess[0][0];
		zero_index++;
		zero_arr[zero_index]=primary_guess[0][1];
		zero_index++;
	}	
}
//shomarande tedad 2 haye mojud dar ramz
int two_counter(int guess_modified[2][pass_length])
{
	char react_get[4];
	int i_index;
	int new_two_index=0;
	
	scanf("%s",react_get);
	for(i_index=0;i_index<4;i_index++)
	{
		guess_modified[1][i_index]=react_get[i_index]-48;
	}
	for(i_index=0;i_index<4;i_index++)
	{
		if(guess_modified[1][i_index]==2)
			new_two_index++;
	}
	return new_two_index;
}
//ba komake adade be dast amade va etelaate tabe (information_primary_rand_guess) mitavinm adad ra ba komake tabe zir peida konim
void moify_rand_guess(int guess_modified[2][pass_length])
{
	char react_get[4];
	int guess_cpy[2][4]={0};
	int new_two_index,i_index,j_index, on=0;
	// baraye different counter 4 halat vojud darad
	switch (different_counter)
	{
		case 1:
			{
				for(i_index=0;i_index<4;i_index++)
				{
					guess_modified[0][i_index]=new_guess[0];
				}
				show_guess(guess_modified);
				do
				{
					on=0;
					new_two_index=two_counter(guess_modified);
					if(new_two_index!=4)
					{
						on++;
						printf("The guidance was wrong. Be more careful and helpful.\n");
					}
				}while(on);	
			}
			break;
			
		case 2:
			{
				if(guess_modified[1][0]!=2)
				{
					if(new_guess[0]%2==0)
					{
						guess_modified[0][0]=new_guess[1];
						guess_cpy[0][0]=new_guess[1];
						guess_modified[1][0]=2;
					}
					else
					{
						guess_modified[0][0]=new_guess[0];
						guess_modified[1][0]=2;
						guess_cpy[0][0]=new_guess[0];
					}	
				}
				else
				{
					guess_cpy[0][0]=guess_modified[0][0];
				}
				for(i_index=1;i_index<5;i_index++)
				{
					if(i_index!=4)
					{
						if(guess_modified[1][i_index]!=2)
						{
							guess_cpy[0][i_index]=new_guess[0];
						}
						else
						{
							guess_cpy[0][i_index]=guess_modified[0][i_index];
						}
						for(j_index=i_index+1;j_index<4;j_index++)
						{
							if(guess_modified[1][j_index]!=2)
								guess_cpy[0][j_index]=zero_arr[0];
							else
								guess_cpy[0][j_index]=guess_modified[0][i_index];
						}
						show_guess(guess_cpy);
						new_two_index=two_counter(guess_cpy);
						if(new_two_index==4)
						{
							break;
						}
						for(j_index=0;j_index<4;j_index++)
						{
							if(guess_cpy[1][j_index]==1)
							{
								guess_modified[0][i_index]=new_guess[1];
								guess_cpy[0][i_index]=new_guess[1];
								guess_modified[1][i_index]=2;
							}
							if(guess_cpy[1][j_index]==2&& new_two_index>i_index)
							{
								guess_modified[0][i_index]=new_guess[0];
								guess_modified[1][i_index]=2;
							}
						}
					}
					else
					{
						guess_cpy[0][3]=new_guess[1];
						show_guess(guess_cpy);
						int on;
						do
						{
							on=0;
							new_two_index=two_counter(guess_cpy);
							if(new_two_index!=4)
							{
								on++;
								printf("The guidance was wrong. Be more careful and helpful.\n");
							}
						}while(on);
					}
				}
			}
			break;
			
		case 3:
			{
				guess_cpy[0][0]=new_guess[0];
				guess_cpy[0][1]=new_guess[0];
				guess_cpy[0][2]=new_guess[1];
				guess_cpy[0][3]=new_guess[1];
				show_guess(guess_cpy);
				new_two_index=two_counter(guess_cpy);
				if(new_two_index==0)
				{
					guess_cpy[0][0]=new_guess[0];
					guess_cpy[0][1]=new_guess[0];			
					guess_cpy[0][2]=new_guess[2];
					guess_cpy[0][3]=new_guess[2];
					show_guess(guess_cpy);
					new_two_index=two_counter(guess_cpy);
					if(new_two_index==1)
					{
						guess_cpy[0][0]=new_guess[2];
						guess_cpy[0][1]=new_guess[1];			
						guess_cpy[0][2]=new_guess[2];
						guess_cpy[0][3]=new_guess[0];
						show_guess(guess_cpy);
						new_two_index=two_counter(guess_cpy);
						if(new_two_index==4)
							return;
						if(new_two_index==0)
						{
							guess_cpy[0][0]=new_guess[1];
							guess_cpy[0][1]=new_guess[2];			
							guess_cpy[0][2]=new_guess[0];
							guess_cpy[0][3]=new_guess[2];
							show_guess(guess_cpy);
							new_two_index=two_counter(guess_cpy);
							if(new_two_index==4)
								return;
						}
						if(new_two_index==2)
						{
							guess_cpy[0][0]=new_guess[2];
							guess_cpy[0][1]=new_guess[1];			
							guess_cpy[0][2]=new_guess[0];
							guess_cpy[0][3]=new_guess[2];
							show_guess(guess_cpy);
							new_two_index=two_counter(guess_cpy);
							if(new_two_index==4)
								return;
							if(new_two_index==0)
							{
								guess_cpy[0][0]=new_guess[1];
								guess_cpy[0][1]=new_guess[2];			
								guess_cpy[0][2]=new_guess[2];
								guess_cpy[0][3]=new_guess[0];
								show_guess(guess_cpy);
								new_two_index=two_counter(guess_cpy);
								if(new_two_index==4)
									return;
							}
						}	
					}
					if(new_two_index==0)
					{
						guess_cpy[0][0]=new_guess[2];
						guess_cpy[0][1]=new_guess[1];			
						guess_cpy[0][2]=new_guess[0];
						guess_cpy[0][3]=new_guess[0];
						show_guess(guess_cpy);
						new_two_index=two_counter(guess_cpy);
						if(new_two_index==4)
							return;
						if(new_two_index==2)
						{
							guess_cpy[0][0]=new_guess[1];
							guess_cpy[0][1]=new_guess[2];			
							guess_cpy[0][2]=new_guess[0];
							guess_cpy[0][3]=new_guess[0];
							show_guess(guess_cpy);
							new_two_index=two_counter(guess_cpy);
							if(new_two_index==4)
								return;
						}
					}
				}
				if(new_two_index==2)
				{
					guess_cpy[0][0]=new_guess[0];
					guess_cpy[0][1]=new_guess[0];			
					guess_cpy[0][2]=new_guess[2];
					guess_cpy[0][3]=new_guess[2];
					show_guess(guess_cpy);
					new_two_index=two_counter(guess_cpy);
					if(new_two_index==2)
					{
						guess_cpy[0][0]=new_guess[2];
						guess_cpy[0][1]=new_guess[0];			
						guess_cpy[0][2]=new_guess[2];
						guess_cpy[0][3]=new_guess[1];
						show_guess(guess_cpy);
						new_two_index=two_counter(guess_cpy);
						if(new_two_index==4)
							return;
						if(new_two_index==0)
						{
							guess_cpy[0][0]=new_guess[0];
							guess_cpy[0][1]=new_guess[2];			
							guess_cpy[0][2]=new_guess[1];
							guess_cpy[0][3]=new_guess[2];
							show_guess(guess_cpy);
							new_two_index=two_counter(guess_cpy);
							if(new_two_index==4)
								return;
						}
						if(new_two_index==2)
						{
							guess_cpy[0][0]=new_guess[2];
							guess_cpy[0][1]=new_guess[0];			
							guess_cpy[0][2]=new_guess[1];
							guess_cpy[0][3]=new_guess[2];
							show_guess(guess_cpy);
							new_two_index=two_counter(guess_cpy);
							if(new_two_index==4)
								return;
							if(new_two_index==0)
							{
								guess_cpy[0][0]=new_guess[0];
								guess_cpy[0][1]=new_guess[2];			
								guess_cpy[0][2]=new_guess[2];
								guess_cpy[0][3]=new_guess[1];
								show_guess(guess_cpy);
								new_two_index=two_counter(guess_cpy);
								if(new_two_index==4)
									return;
							}
						}	
					}
					if(new_two_index==1)
					{
						guess_cpy[0][0]=new_guess[0];
						guess_cpy[0][1]=new_guess[2];			
						guess_cpy[0][2]=new_guess[1];
						guess_cpy[0][3]=new_guess[0];
						show_guess(guess_cpy);
						new_two_index=two_counter(guess_cpy);
						if(new_two_index==4)
							return;
						if(new_two_index==2)
						{
							guess_cpy[0][0]=new_guess[2];
							guess_cpy[0][1]=new_guess[0];			
							guess_cpy[0][2]=new_guess[1];
							guess_cpy[0][3]=new_guess[0];
							show_guess(guess_cpy);
							new_two_index=two_counter(guess_cpy);
							if(new_two_index==4)
								return;
							if(new_two_index==0)
							{
								guess_cpy[0][0]=new_guess[0];
								guess_cpy[0][1]=new_guess[2];			
								guess_cpy[0][2]=new_guess[0];
								guess_cpy[0][3]=new_guess[1];
								show_guess(guess_cpy);
								new_two_index=two_counter(guess_cpy);
								if(new_two_index==4)
									return;
							}
						}
					}
				}
				if(new_two_index==1)
				{
					guess_cpy[0][2]=new_guess[2];
					guess_cpy[0][3]=new_guess[2];
					show_guess(guess_cpy);
					new_two_index=two_counter(guess_cpy);
					if(new_two_index==3)
					{
						guess_cpy[0][0]=new_guess[0];
						guess_cpy[0][1]=new_guess[1];
						guess_cpy[0][2]=new_guess[2];
						guess_cpy[0][3]=new_guess[2];
						show_guess(guess_cpy);
						new_two_index=two_counter(guess_cpy);
						if(new_two_index==4)
							return;
						if(new_two_index==2)
						{
							guess_cpy[0][0]=new_guess[1];
							guess_cpy[0][1]=new_guess[0];
							show_guess(guess_cpy);
							new_two_index=two_counter(guess_cpy);
							if(new_two_index==4)
								return;
						}
					}
					if(new_two_index==2)
					{
						guess_cpy[0][0]=new_guess[0];
						guess_cpy[0][1]=new_guess[1];
						guess_cpy[0][2]=new_guess[2];
						guess_cpy[0][3]=new_guess[0];
						show_guess(guess_cpy);
						new_two_index=two_counter(guess_cpy);
						if(new_two_index==4)
							return;
						if(new_two_index==2)
						{
							guess_cpy[0][0]=new_guess[1];
							guess_cpy[0][1]=new_guess[0];
							show_guess(guess_cpy);
							new_two_index=two_counter(guess_cpy);
							if(new_two_index==4)
								return;
							if(two_index==0)
							{
								guess_cpy[0][0]=new_guess[0];
								guess_cpy[0][1]=new_guess[1];
								guess_cpy[0][2]=new_guess[0];
								guess_cpy[0][3]=new_guess[2];
								show_guess(guess_cpy);
								new_two_index=two_counter(guess_cpy);
								if(new_two_index==4)
									return;
							}
						}
						if(new_two_index==0)
						{
							guess_cpy[0][0]=new_guess[1];
							guess_cpy[0][1]=new_guess[0];
							guess_cpy[0][2]=new_guess[0];
							guess_cpy[0][3]=new_guess[2];
							show_guess(guess_cpy);
							new_two_index=two_counter(guess_cpy);
							if(new_two_index==4)
								return;
						}
					}
					if(new_two_index==0)
					{
						guess_cpy[0][0]=new_guess[2];
						guess_cpy[0][1]=new_guess[2];
						guess_cpy[0][2]=new_guess[0];
						guess_cpy[0][3]=new_guess[1];
						show_guess(guess_cpy);
						new_two_index=two_counter(guess_cpy);
						if(new_two_index==4)
							return;
						if(new_two_index==2)
						{
							guess_cpy[0][2]=new_guess[1];
							guess_cpy[0][3]=new_guess[0];
							show_guess(guess_cpy);
							new_two_index=two_counter(guess_cpy);
							if(new_two_index==4)
								return;
						}
						if(new_two_index==1)
						{
							guess_cpy[0][0]=new_guess[1];
							guess_cpy[0][2]=new_guess[1];
							guess_cpy[0][3]=new_guess[0];
							show_guess(guess_cpy);
							new_two_index=two_counter(guess_cpy);
							if(new_two_index==4)
								return;
							if(new_two_index==2)
							{
								guess_cpy[0][1]=new_guess[1];
								guess_cpy[0][0]=new_guess[2];
								show_guess(guess_cpy);
								new_two_index=two_counter(guess_cpy);
								if(new_two_index==4)
									return;
							}	
						}
						if(new_two_index==3)
						{
							guess_cpy[0][0]=new_guess[1];
							show_guess(guess_cpy);
							new_two_index=two_counter(guess_cpy);
							if(new_two_index==4)
								return;
							if(new_two_index==2)
							{
								guess_cpy[0][0]=new_guess[2];
								guess_cpy[0][1]=new_guess[1];
								show_guess(guess_cpy);
								new_two_index=two_counter(guess_cpy);
								if(new_two_index==4)
									return;
							}
						}			
					}
				}		
				if(new_two_index==3)
				{
					guess_cpy[0][2]=new_guess[2];
					guess_cpy[0][3]=new_guess[2];
					show_guess(guess_cpy);
					new_two_index=two_counter(guess_cpy);
					if(new_two_index==1)
					{
						guess_cpy[0][0]=new_guess[2];
						guess_cpy[0][1]=new_guess[0];
						guess_cpy[0][2]=new_guess[1];
						guess_cpy[0][3]=new_guess[1];
						show_guess(guess_cpy);
						new_two_index=two_counter(guess_cpy);
						if(new_two_index==4)
							return;
						if(new_two_index==2)
						{
							guess_cpy[0][0]=new_guess[0];
							guess_cpy[0][1]=new_guess[2];
							show_guess(guess_cpy);
							new_two_index=two_counter(guess_cpy);
							if(new_two_index==4)
								return;
						}
					}
					if(new_two_index==3)
					{
						guess_cpy[0][0]=new_guess[0];
						guess_cpy[0][1]=new_guess[0];
						guess_cpy[0][2]=new_guess[2];
						guess_cpy[0][3]=new_guess[1];
						show_guess(guess_cpy);
						new_two_index=two_counter(guess_cpy);
						if(new_two_index==4)
							return;
						if(new_two_index==2)
						{
							guess_cpy[0][2]=new_guess[1];
							guess_cpy[0][3]=new_guess[2];
							show_guess(guess_cpy);
							new_two_index=two_counter(guess_cpy);
							if(new_two_index==4)
								return;
						}
					}
				}
			}
			break;
			
		case 4:
			{
				int state=0;
				guess_cpy[0][0]=new_guess[0];
				guess_cpy[0][1]=new_guess[0];
				guess_cpy[0][2]=new_guess[1];
				guess_cpy[0][3]=new_guess[1];
				show_guess(guess_cpy);
				new_two_index=two_counter(guess_cpy);
				if(new_two_index==0)
				{
					guess_modified[0][0]=new_guess[1];
					guess_modified[0][2]=new_guess[0];
					state=1;
				}
				if(new_two_index==2)
				{
					guess_modified[0][0]=new_guess[0];
					guess_modified[0][2]=new_guess[1];
					state=1;
				}
				if(state==1)
				{
					guess_cpy[0][0]=new_guess[2];
					guess_cpy[0][1]=new_guess[2];
					guess_cpy[0][2]=new_guess[3];
					guess_cpy[0][3]=new_guess[3];
					show_guess(guess_cpy);
					new_two_index=two_counter(guess_cpy);
					if(new_two_index==0)
					{
						guess_modified[0][1]=new_guess[2];
						guess_modified[0][3]=new_guess[3];
					}
					if(new_two_index==2)
					{
						guess_modified[0][1]=new_guess[3];
						guess_modified[0][3]=new_guess[2];
					}
				}
				if(new_two_index==1)
				{
					guess_cpy[0][2]=new_guess[2];
					guess_cpy[0][3]=new_guess[2];
					show_guess(guess_cpy);
					new_two_index=two_counter(guess_cpy);
					if(new_two_index==0)
					{
						guess_modified[0][0]=new_guess[2];
						guess_modified[0][1]=new_guess[3];
						guess_modified[0][2]=new_guess[0];
						guess_modified[0][3]=new_guess[1];
					}
					if(new_two_index==2)
					{
						guess_modified[0][0]=new_guess[0];
						guess_modified[0][1]=new_guess[1];
						guess_modified[0][2]=new_guess[2];
						guess_modified[0][3]=new_guess[3];
					}
				}
				show_guess(guess_modified);
				new_two_index=two_counter(guess_cpy);
				if(new_two_index==0)
				{
					int temp;
					temp=guess_modified[0][0];
					guess_modified[0][0]=guess_modified[0][1];
					guess_modified[0][1]=temp;
					
					temp=guess_modified[0][2];
					guess_modified[0][2]=guess_modified[0][3];
					guess_modified[0][3]=temp;
					show_guess(guess_modified);
					scanf("%s",react_get);
					return;
				}
				if(new_two_index==4)
				{
					return;	
				}
				if(new_two_index==2)
				{
					int temp;
					temp=guess_modified[0][0];
					guess_modified[0][0]=guess_modified[0][1];
					guess_modified[0][1]=temp;
					show_guess(guess_modified);
					new_two_index=two_counter(guess_modified);
					if(new_two_index==4)
						return;
					if(new_two_index==0)
					{	
						int temp;
						temp=guess_modified[0][0];
						guess_modified[0][0]=guess_modified[0][1];
						guess_modified[0][1]=temp;
						
						temp=guess_modified[0][2];
						guess_modified[0][2]=guess_modified[0][3];
						guess_modified[0][3]=temp;
						show_guess(guess_modified);
						scanf("%s",react_get);
						return;
					}
				}
			}		
			
			break;
	}
}


int main() {
	int verify;
	int choice;
	do
	{
		verify=0;
		printf("Please choose the Nezam mode:\n");
		printf("1)Nezam with correct reaction:\n");
		printf("2)Nezam with random reaction:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: 
				{
					printf("Please enter the length of the password:\n");
					scanf("%d",&pass_length);
					int primary_guess[2][4]={0};
					int guess[2][pass_length];
					int guess_modified[2][pass_length];
					int one_save[pass_length];
					int two_save[pass_length];
					int foo1=0,foo2=0;
					int i_index,j_index=0;
	
					condition=1;
					// marahele ebtedaeeie peida kardane digit haye ramz
					while (number<12)
					{
						primary_guess_file(primary_guess);
						//namayshe hadse avalie
						show_guess(primary_guess);
						// reaction aval bayad az shirfarhad daryaft shavad
						get_react( primary_guess);
						//save kardan dar password
						cpy_in_pass_primaryguess( primary_guess);
					}
					// por krdane guess ba adade be dast amade baraye yaftan rammz
					for(i_index=0;i_index<12;i_index++)
					{
						if(password[1][i_index]==2)
						{
							guess[0][password[3][i_index]]=i_index;
							guess_modified[0][password[3][i_index]]=i_index;
							guess_modified[1][password[3][i_index]]=2;
						}
					}
					j_index=0;
					int i=0,j=0;
					for(i_index=0;i_index<12;i_index++)
					{
					
						if(password[1][i_index]==1)
						{
							one_save[i]=i_index;
							i++;	
						}
					}

					for(i_index=0;i_index<12;i_index++)
					{
						if(password[1][i_index]==2)
						{
							two_save[j]=i_index;
							j++;	
						}
					}

					//shomordane arghame motemayez
					for(i_index=0;i_index<12;i_index++)
					{
						if(password[1][i_index]!=3)
						{
							different_counter++;			
						}
					}
					
					for(i_index=0;i_index<i;i_index++)
					{
						for(j_index=0;j_index<pass_length;j_index++)
						{
							if(guess_modified[1][j_index]!=2)
							{
								guess_modified[0][j_index]=one_save[i_index];
							}
						}
						show_guess(guess_modified);
						get_react(guess_modified);
						cpy_in_pass(guess_modified);
						two_index=0;
						for(j_index=0;j_index<pass_length;j_index++)
						{
							if(guess_modified[1][j_index]==2)
							{
								guess[0][j_index]=guess_modified[0][j_index];
							}
						}
						two_index=0;
						for(j_index=0;j_index<pass_length;j_index++)
						{
							if(guess_modified[1][j_index]==2)
							{
								two_index++;
							}
						}
						if(two_index==pass_length)
							return 0;
					}
					two_index=0;
					for(i_index=0;i_index<pass_length;i_index++)
					{
						if(guess_modified[1][i_index]==2)
						{
							two_index++;
						}
					}
					if(two_index!=pass_length)
					{
						for(i_index=0;i_index<j;i_index++)
						{
							for(j_index=0;j_index<pass_length;j_index++)
							{
								if(guess_modified[1][j_index]!=2)
								{
									guess_modified[0][j_index]=two_save[i_index];
								}
							}
							show_guess(guess_modified);
							get_react(guess_modified);
							cpy_in_pass(guess_modified);
							two_index=0;
							for(j_index=0;j_index<pass_length;j_index++)
							{
								if(guess_modified[1][j_index]==2)
								{
									guess[0][j_index]=guess_modified[0][j_index];
								}
							}
							two_index=0;
							for(j_index=0;j_index<pass_length;j_index++)
							{
								if(guess_modified[1][j_index]==2)
								{
									two_index++;
								}
							}
							if(two_index==pass_length)
								return 0;
							}
					}
					if(guess_index>10)
					{
						printf("Ruuuuun!!!");
						return 0;
					}
				}
				break;
			case 2:
				{
					int primary_guess[2][4]={0};
					int guess_modified[2][pass_length];
					printf("WARNING: (the password length only can be 4)\n");					
					pass_length=4;
					condition=2;
					while(number<12 &&different_counter<pass_length)
					{
						random_guess(primary_guess);
						show_guess(primary_guess);
						get_react(primary_guess);
						information_primary_rand_guess(guess_modified,primary_guess);
					}
					moify_rand_guess(guess_modified);
					if(guess_index>10)
					{
						printf("Ruuuuun!!!");
						return 0;
					}
				}
				break;
			default:
				{
					printf("invalid choice!!! please try again.\n\n");
					verify++;
				}
		}
	}while(verify);

	return 0;
}
