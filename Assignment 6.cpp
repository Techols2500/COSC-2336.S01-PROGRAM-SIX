//************************************************************************** 
//
// Programming Excerise 6 
// CLASS: COSC 2336.S01
// AUTHOR: TYLER ECHOLS 
// DAtE: Nov 2017  
//
//**************************************************************************

#include <iostream>
#include <fstream>
#include <array>
#include <string>
#include <string.h>

using namespace std;


void	Path(int	Cost[12][12]);

int		Cost[12][12];
char	MinPath[12];
char	CurrPath[12];
bool	Visited[12];
int		MaxCost = INT_MAX;
int		MinCost = MaxCost;;
int		NodesInUse;
int		longest = -1;
int		calculated = 0; 




void main()
{
	fstream infile;
	infile.open("ReadFromThisFile.txt", ios_base::in); 
	string currentline; 
	char Letter1; 
	char Letter2; 
	string lengthChar; 
	int index1 = 0; 
	int index2 = 0; 
	int length = 0;
	int longestlength = -1; 
	bool check = true;
	//----------------------------------------READING FROM THE FILE AND FILLING THE ARRAYS---------------------------------------------
	if (infile.is_open() && !infile.eof())  
	{
		getline(infile, currentline);       
		NodesInUse = atoi(currentline.c_str()); 
	}

	if (currentline.length() > 0)
	{
		for (int i = 0; i < currentline.length(); i++)
		{
			if (!(isdigit(currentline.at(i))))
			{
				check = false;
			}
			else
			{
				if ((NodesInUse < 1) || (NodesInUse > 12))
				{
					check = false;
				}
			}
		}
	}
	else
	{
		check = false;
	}

	for (int k = 0; k < NodesInUse; k++)        
	{
		for (int j = 0; j < NodesInUse; j++)
		{
			Cost[k][j] = 0;
		}
	}

	for (int k = 0; k < NodesInUse; k++)	   
	{
		Visited[k] = false;				   
		MinPath[k] = '?';			  
		CurrPath[k] = '?';			   
	}


	while (!(infile.eof()))						   
	{
		getline(infile, currentline);			   
		if (currentline.length() != 0)			   
		{
			Letter1 = currentline.at(0);	   
			Letter2 = currentline.at(1);      
			lengthChar = currentline.substr(2);  
			if ((lengthChar.length()) > longestlength)
			{
				longestlength = lengthChar.length();
			}
			index1 = Letter1 - 'A';		   
			index2 = Letter2 - 'A';		   
			length = atoi(lengthChar.c_str()); 
			Cost[index1][index2] = length;  
		}
		 
	}



	//----------------------------------------CALCULATING SHORTEST PATH---------------------------------------------

	if (check != false)
	{
		Path(Cost);				   





	 //----------------------------------------PRINTING THE SHORTEST PATH AND THE Cost---------------------------------------------

		cout << "  ";								   
		for (int k = 0; k < NodesInUse; k++)
		{
			char c = 65 + k;
			cout << c << " ";
		}
		cout << "\n";

		for (int k = 0; k < NodesInUse; k++)		       
		{
			char c = 65 + k;
			cout << c << " ";			               
			for (int j = 0; j < NodesInUse; j++)
			{
				cout << Cost[k][j] << " ";
			}
			cout << "\n";
		}

		if (MinCost < MaxCost)		   
		{
			cout << "\nThe minimum cost was " << MinCost << endl;
			cout << "The minimum path was ";
			for (int k = 0; k < NodesInUse; k++)
			{
				cout << MinPath[k] << " ";
			}
			cout << "\n";
		}
		else
		{
			cout << "\nThe minimum path is too long to be stored in an integer. You cannot reach all of the nodes in this Cost." << endl;
		}

		
	}
	else
	{
		cout << "The file contains an invalid number of nodes" << endl;
	}
}

void Path(int Cost[12][12])
{
	int tempSize = 0; 

	for (int a = 0; a < NodesInUse && NodesInUse > 0; a++) 
	{
		tempSize = 0;
		for (int z = 0; z < NodesInUse; z++)
		{
			Visited[z] = 0;
		}
		CurrPath[0] = a + 'A';
		tempSize += Cost[a][a];
		Visited[a] = true;
		if (NodesInUse == 1)
		{
			if (tempSize < MinCost)
			{
				for (int z = 0; z < NodesInUse; z++)
				{
					MinPath[z] = CurrPath[z];
				}
				MinCost = tempSize;
			}
			calculated++;
		}
		for (int b = 0; b < NodesInUse && NodesInUse > 1; b++) 
		{
			for (int z = 0; z < NodesInUse; z++)
			{
				Visited[z] = 0;
			}
			Visited[a] = true;
			if ((Visited[b] != true) && (Cost[a][b] > 0))
			{
				CurrPath[1] = b + 'A';
				tempSize = 0;
				tempSize += Cost[a][b];
				Visited[b] = true;
				if (NodesInUse == 2)
				{
					if (tempSize < MinCost)
					{
						for (int z = 0; z < NodesInUse; z++)
						{
							MinPath[z] = CurrPath[z];
						}
						MinCost = tempSize;
					}
					calculated++;
				}
				for (int c = 0; c < NodesInUse && NodesInUse > 2; c++) 
				{
					for (int z = 0; z < NodesInUse; z++)
					{
						Visited[z] = 0;
					}
					Visited[a] = true;
					Visited[b] = true;
					if ((Visited[c] != true) && (Cost[b][c] > 0))
					{
						CurrPath[2] = c + 'A';
						tempSize = 0;
						tempSize += Cost[a][b];
						tempSize += Cost[b][c];
						Visited[c] = true;

						if (NodesInUse == 3)
						{
							if (tempSize < MinCost)
							{
								for (int z = 0; z < NodesInUse; z++)
								{
									MinPath[z] = CurrPath[z];
								}
								MinCost = tempSize;
							}
							calculated++;
						}
						for (int d = 0; d < NodesInUse && NodesInUse > 3; d++) 
						{
							for (int z = 0; z < NodesInUse; z++)
							{
								Visited[z] = 0;
							}
							Visited[a] = true;
							Visited[b] = true;
							Visited[c] = true;
							if ((Visited[d] != true) && (Cost[c][d] > 0))
							{
								CurrPath[3] = d + 'A';
								tempSize = 0;
								tempSize += Cost[a][b];
								tempSize += Cost[b][c];
								tempSize += Cost[c][d];
								Visited[d] = true;

								if (NodesInUse == 4)
								{
									if (tempSize < MinCost)
									{
										for (int z = 0; z < NodesInUse; z++)
										{
											MinPath[z] = CurrPath[z];
										}
										MinCost = tempSize;
									}
									calculated++;
								}
								for (int e = 0; e < NodesInUse && NodesInUse > 4; e++) 
								{
									for (int z = 0; z < NodesInUse; z++)
									{
										Visited[z] = 0;
									}
									Visited[a] = true;
									Visited[b] = true;
									Visited[c] = true;
									Visited[d] = true;
									if ((Visited[e] != true) && (Cost[d][e] > 0))
									{
										CurrPath[4] = e + 'A';
										tempSize = 0;
										tempSize += Cost[a][b];
										tempSize += Cost[b][c];
										tempSize += Cost[c][d];
										tempSize += Cost[d][e];
										Visited[e] = true;


										if (NodesInUse == 5)
										{
											if (tempSize < MinCost)
											{
												for (int z = 0; z < NodesInUse; z++)
												{
													MinPath[z] = CurrPath[z];
												}
												MinCost = tempSize;
											}
											calculated++;
										}
										for (int f = 0; f < NodesInUse && NodesInUse > 5; f++) 
										{
											for (int z = 0; z < NodesInUse; z++)
											{
												Visited[z] = 0;
											}
											Visited[a] = true;
											Visited[b] = true;
											Visited[c] = true;
											Visited[d] = true;
											Visited[e] = true;
											if ((Visited[f] != true) && (Cost[e][f] > 0))
											{
												CurrPath[5] = f + 'A';
												tempSize = 0;
												tempSize += Cost[a][b];
												tempSize += Cost[b][c];
												tempSize += Cost[c][d];
												tempSize += Cost[d][e];
												tempSize += Cost[e][f];
												Visited[f] = true;


												if (NodesInUse == 6)
												{
													if (tempSize < MinCost)
													{
														for (int z = 0; z < NodesInUse; z++)
														{
															MinPath[z] = CurrPath[z];
														}
														MinCost = tempSize;
													}
													calculated++;
												}
												for (int g = 0; g < NodesInUse && NodesInUse > 6; g++) 
												{
													for (int z = 0; z < NodesInUse; z++)
													{
														Visited[z] = 0;
													}
													Visited[a] = true;
													Visited[b] = true;
													Visited[c] = true;
													Visited[d] = true;
													Visited[e] = true;
													Visited[f] = true;
													if ((Visited[g] != true) && (Cost[f][g] > 0))
													{
														CurrPath[6] = g + 'A';
														tempSize = 0;
														tempSize += Cost[a][b];
														tempSize += Cost[b][c];
														tempSize += Cost[c][d];
														tempSize += Cost[d][e];
														tempSize += Cost[e][f];
														tempSize += Cost[f][g];
														Visited[g] = true;


														if (NodesInUse == 7)
														{
															if (tempSize < MinCost)
															{
																for (int z = 0; z < NodesInUse; z++)
																{
																	MinPath[z] = CurrPath[z];
																}
																MinCost = tempSize;
															}
															calculated++;
														}
														for (int h = 0; h < NodesInUse && NodesInUse > 7; h++) 
														{
															for (int z = 0; z < NodesInUse; z++)
															{
																Visited[z] = 0;
															}
															Visited[a] = true;
															Visited[b] = true;
															Visited[c] = true;
															Visited[d] = true;
															Visited[e] = true;
															Visited[f] = true;
															Visited[g] = true;
															if ((Visited[h] != true) && (Cost[g][h] > 0))
															{
																CurrPath[7] = h + 'A';
																tempSize = 0;
																tempSize += Cost[a][b];
																tempSize += Cost[b][c];
																tempSize += Cost[c][d];
																tempSize += Cost[d][e];
																tempSize += Cost[e][f];
																tempSize += Cost[f][g];
																tempSize += Cost[g][h];
																Visited[h] = true;


																if (NodesInUse == 8)
																{
																	if (tempSize < MinCost)
																	{
																		for (int z = 0; z < NodesInUse; z++)
																		{
																			MinPath[z] = CurrPath[z];
																		}
																		MinCost = tempSize;
																	}
																	calculated++;
																}

																for (int i = 0; i < NodesInUse && NodesInUse > 8; i++) 
																{
																	for (int z = 0; z < NodesInUse; z++)
																	{
																		Visited[z] = 0;
																	}
																	Visited[a] = true;
																	Visited[b] = true;
																	Visited[c] = true;
																	Visited[d] = true;
																	Visited[e] = true;
																	Visited[f] = true;
																	Visited[g] = true;
																	Visited[h] = true;
																	if ((Visited[i] != true) && (Cost[h][i] > 0))
																	{
																		CurrPath[8] = i + 'A';
																		tempSize = 0;
																		tempSize += Cost[a][b];
																		tempSize += Cost[b][c];
																		tempSize += Cost[c][d];
																		tempSize += Cost[d][e];
																		tempSize += Cost[e][f];
																		tempSize += Cost[f][g];
																		tempSize += Cost[g][h];
																		tempSize += Cost[h][i];
																		Visited[i] = true;


																		if (NodesInUse == 9)
																		{
																			if (tempSize < MinCost)
																			{
																				for (int z = 0; z < NodesInUse; z++)
																				{
																					MinPath[z] = CurrPath[z];
																				}
																				MinCost = tempSize;
																			}
																			calculated++;
																		}

																		for (int j = 0; j < NodesInUse && NodesInUse > 9; j++) 
																		{
																			for (int z = 0; z < NodesInUse; z++)
																			{
																				Visited[z] = 0;
																			}
																			Visited[a] = true;
																			Visited[b] = true;
																			Visited[c] = true;
																			Visited[d] = true;
																			Visited[e] = true;
																			Visited[f] = true;
																			Visited[g] = true;
																			Visited[h] = true;
																			Visited[i] = true;
																			if ((Visited[j] != true) && (Cost[i][j] > 0))
																			{
																				CurrPath[9] = j + 'A';
																				tempSize = 0;
																				tempSize += Cost[a][b];
																				tempSize += Cost[b][c];
																				tempSize += Cost[c][d];
																				tempSize += Cost[d][e];
																				tempSize += Cost[e][f];
																				tempSize += Cost[f][g];
																				tempSize += Cost[g][h];
																				tempSize += Cost[h][i];
																				tempSize += Cost[i][j];
																				Visited[j] = true;

																				if (NodesInUse == 10)
																				{
																					if (tempSize < MinCost)
																					{
																						for (int z = 0; z < NodesInUse; z++)
																						{
																							MinPath[z] = CurrPath[z];
																						}
																						MinCost = tempSize;
																					}
																					calculated++;
																				}
																				for (int k = 0; k < NodesInUse && NodesInUse > 10; k++) 
																				{
																					for (int z = 0; z < NodesInUse; z++)
																					{
																						Visited[z] = 0;
																					}
																					Visited[a] = true;
																					Visited[b] = true;
																					Visited[c] = true;
																					Visited[d] = true;
																					Visited[e] = true;
																					Visited[f] = true;
																					Visited[g] = true;
																					Visited[h] = true;
																					Visited[i] = true;
																					Visited[j] = true;
																					if ((Visited[k] != true) && (Cost[j][k] > 0))
																					{
																						CurrPath[10] = k + 'A';
																						tempSize = 0;
																						tempSize += Cost[a][b];
																						tempSize += Cost[b][c];
																						tempSize += Cost[c][d];
																						tempSize += Cost[d][e];
																						tempSize += Cost[e][f];
																						tempSize += Cost[f][g];
																						tempSize += Cost[g][h];
																						tempSize += Cost[h][i];
																						tempSize += Cost[i][j];
																						tempSize += Cost[j][k];
																						Visited[k] = true;

																						if (NodesInUse == 11)
																						{
																							if (tempSize < MinCost)
																							{
																								for (int z = 0; z < NodesInUse; z++)
																								{
																									MinPath[z] = CurrPath[z];
																								}
																								MinCost = tempSize;
																							}
																							calculated++;
																						}

																						for (int l = 0; l < NodesInUse && NodesInUse > 11; l++) 
																						{
																							for (int z = 0; z < NodesInUse; z++)
																							{
																								Visited[z] = 0;
																							}
																							Visited[a] = true;
																							Visited[b] = true;
																							Visited[c] = true;
																							Visited[d] = true;
																							Visited[e] = true;
																							Visited[f] = true;
																							Visited[g] = true;
																							Visited[h] = true;
																							Visited[i] = true;
																							Visited[j] = true;
																							Visited[k] = true;
																							if ((Visited[l] != true) && (Cost[k][l] > 0))
																							{
																								CurrPath[11] = l + 'A';
																								tempSize = 0;
																								tempSize += Cost[a][b];
																								tempSize += Cost[b][c];
																								tempSize += Cost[c][d];
																								tempSize += Cost[d][e];
																								tempSize += Cost[e][f];
																								tempSize += Cost[f][g];
																								tempSize += Cost[g][h];
																								tempSize += Cost[h][i];
																								tempSize += Cost[i][j];
																								tempSize += Cost[j][k];
																								tempSize += Cost[k][l];
																								Visited[l] = true;

																								if (NodesInUse == 12)
																								{
																									if (tempSize < MinCost)
																									{
																										for (int z = 0; z < NodesInUse; z++)
																										{
																											MinPath[z] = CurrPath[z];
																										}
																										MinCost = tempSize;
																									}
																									calculated++;
																								}

																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

