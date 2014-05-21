// techimet4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "malloc.h"
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <locale.h>

/** @struct tree
@brief ��������� ������
@var info ������.
@var left ��������� �� ������ ����.
@var right ��������� �� ������� ����.
 **/
struct tree {
  char info;
  struct tree *left;
  struct tree *right;
  };

/**
@function stree
@brief ���������� ������ ��������
@param RR �������� �������
@param r ����� �������
@param info ������
@return RR �������� ������� � ���������� �� �����**/
tree *stree(
  tree *RR,
  tree *r,
  char info  
  )
{
  if(!r)/**�������� ������� ����. � ������ ��� ���������� ��������� �����,
		� ��������� ������ ��������� ���������� ���� � ������������ � ��������
		� ��������� ������ �������� �� ���� �������� **/ {
    r = new tree;
    if(!r) {
      printf("�� ������� ������\n");
      exit(0);
    }
    r->left = NULL;
    r->right = NULL;
    r->info = info;
    if(!RR)
		{
			
			return r;}/* ������ ���� */
    if(info < RR->info) 
		{
			RR->left = r;
			
	}

    else 
		{
			RR->right = r;
			
	}
	return r;
  }
  if(info < r->info) 
    stree(r,r->left,info);
  else
    stree(r,r->right,info);

  return RR; 
}

/**
@function inorder
@brief �������������� �����
@param RR ������
@return ������� ���������� ������ ��������**/
void inorder(struct tree *RR)
{
  if(!RR) return;

  inorder(RR->left);
  if(RR->info) printf("%c ", RR->info);
  inorder(RR->right);
}


/**
@function preorder
@brief ������ �����
@param RR ������
@return ������� ���������� ������ ��������**/
void preorder(struct tree *RR)
{
  if(!RR) return;

  if(RR->info) printf("%c ", RR->info);
  preorder(RR->left);
  preorder(RR->right);
}


/**
@function postorder
@brief �������� �����
@param RR ������
@return ������� ���������� ������ ��������**/
void postorder(struct tree *RR)
{
  if(!RR) return;

  postorder(RR->left);
  postorder(RR->right);
  if(RR->info) printf("%c ", RR->info);
}






int _tmain(int argc, _TCHAR* argv[])
{
	setlocale( LC_CTYPE, ".1251" );
	char s[80];
	tree* RR;

	RR = NULL;  /* ������������� ����� ������ */

	do {
    printf("������� �����: ");
    gets(s);
    RR = stree(RR, RR, *s);
  } while(*s);

	std::cout << "������������ �����";
	inorder(RR);
	std::cout << std::endl;
	std::cout << "������ �����";
	preorder(RR);
	std::cout << std::endl;
	std::cout << "�������� �����";
	
	postorder(RR);
	std::cout << std::endl;


	return 0;
}

