/**--------------------------------------------------------**/
/**       C o n v e r s i o n   Z vers C (Standard)        **/
/**             Réalisée par Pr D.E ZEGOUR                 **/
/**             E S I - Alger                              **/
/**             Copywrite 2014                             **/
/**--------------------------------------------------------**/

#include <stdio.h>
#include <stdlib.h>
#include <Time.h>
#include <windows.h>

typedef int bool;

#define True 1
#define False 0

/** Implémentation **\: ARBRE BINAIRE DE STRUCTURES**/

/** Structures statiques **/

typedef struct Tib Type_Tib;
typedef Type_Tib *Typestr_Tib;
typedef int Type1_Tib;
typedef bool Type2_Tib;
struct Tib
{
    Type1_Tib Champ1;
    Type2_Tib Champ2;
};

Type1_Tib Struct1_Tib(Typestr_Tib S)
{
    return S->Champ1;
}

Type2_Tib Struct2_Tib(Typestr_Tib S)
{
    return S->Champ2;
}

void Aff_struct1_Tib(Typestr_Tib S, Type1_Tib Val)
{
    S->Champ1 = Val;
}

void Aff_struct2_Tib(Typestr_Tib S, Type2_Tib Val)
{
    S->Champ2 = Val;
}

/** Arbres de recherche binaire **/

typedef Typestr_Tib Typeelem_ATib;
typedef struct Noeud_ATib *Pointeur_ATib;

struct Noeud_ATib
{
    Typeelem_ATib Val;
    Pointeur_ATib Fg;
    Pointeur_ATib Fd;
    Pointeur_ATib Pere;
};

Typeelem_ATib Info_ATib(Pointeur_ATib P)
{
    return P->Val;
}

Pointeur_ATib Fg_ATib(Pointeur_ATib P)
{
    return P->Fg;
}

Pointeur_ATib Fd_ATib(Pointeur_ATib P)
{
    return P->Fd;
}

Pointeur_ATib Pere_ATib(Pointeur_ATib P)
{
    return P->Pere;
}

void Aff_info_ATib(Pointeur_ATib P, Typeelem_ATib Val)
{
    Typeelem_ATib _Temp;
    _Temp = malloc(sizeof(Type_Tib));
    /* Affectation globale de structure */
    _Temp->Champ1 = Val->Champ1;
    _Temp->Champ2 = Val->Champ2;
    Val = _Temp;
    P->Val = Val;
}

void Aff_fg_ATib(Pointeur_ATib P, Pointeur_ATib Q)
{
    P->Fg = Q;
}

void Aff_fd_ATib(Pointeur_ATib P, Pointeur_ATib Q)
{
    P->Fd = Q;
}

void Aff_pere_ATib(Pointeur_ATib P, Pointeur_ATib Q)
{
    P->Pere = Q;
}

void Creernoeud_ATib(Pointeur_ATib *P)
{
    *P = (struct Noeud_ATib *)malloc(sizeof(struct Noeud_ATib));
    (*P)->Val = malloc(sizeof(Type_Tib));
    (*P)->Fg = NULL;
    (*P)->Fd = NULL;
    (*P)->Pere = NULL;
}

void Liberernoeud_ATib(Pointeur_ATib P)
{
    free(P);
}

/** Implémentation **\: PILE DE ARBRES BINAIRES DE STRUCTURES**/
/** Piles **/

typedef Pointeur_ATib Typeelem_PATib;
typedef struct Maillon_PATib *Pointeur_PATib;
typedef Pointeur_PATib Typepile_PATib;

struct Maillon_PATib
{
    Typeelem_PATib Val;
    Pointeur_PATib Suiv;
};

void Creerpile_PATib(Pointeur_PATib *P)
{
    *P = NULL;
}

bool Pilevide_PATib(Pointeur_PATib P)
{
    return (P == NULL);
}

void Empiler_PATib(Pointeur_PATib *P, Typeelem_PATib Val)
{
    Pointeur_PATib Q;

    Q = (struct Maillon_PATib *)malloc(sizeof(struct Maillon_PATib));
    Q->Val = Val;
    Q->Suiv = *P;
    *P = Q;
}

void Depiler_PATib(Pointeur_PATib *P, Typeelem_PATib *Val)
{
    Pointeur_PATib Sauv;

    if (!Pilevide_PATib(*P))
    {
        *Val = (*P)->Val;
        Sauv = *P;
        *P = (*P)->Suiv;
        free(Sauv);
    }
    else
        printf("%s \n", "Pile vide");
}

/** Implémentation **\: LISTE DE ENTIERS**/

/** Listes lin?aires cha?n?es **/

typedef int Typeelem_Li;
typedef struct Maillon_Li *Pointeur_Li;

struct Maillon_Li
{
    Typeelem_Li Val;
    Pointeur_Li Suiv;
};

Pointeur_Li Allouer_Li(Pointeur_Li *P)
{
    *P = (struct Maillon_Li *)malloc(sizeof(struct Maillon_Li));
    (*P)->Suiv = NULL;
}

void Aff_val_Li(Pointeur_Li P, Typeelem_Li Val)
{
    P->Val = Val;
}

void Aff_adr_Li(Pointeur_Li P, Pointeur_Li Q)
{
    P->Suiv = Q;
}

Pointeur_Li Suivant_Li(Pointeur_Li P)
{
    return (P->Suiv);
}

Typeelem_Li Valeur_Li(Pointeur_Li P)
{
    return (P->Val);
}

void Liberer_Li(Pointeur_Li P)
{
    free(P);
}

/** Variables du programme principal **/
Pointeur_ATib L = NULL;
Pointeur_ATib R = NULL;
Pointeur_ATib Copy = NULL;
int V;
int I;
int N;
Pointeur_PATib Steack = NULL;
Pointeur_Li H = NULL;
Pointeur_Li T = NULL;
bool A;
Pointeur_PATib U = NULL;

/** Fonctions standards **/

int Aleanombre(int N)
{
    return (rand() % N);
}

/** Initialisation d'une structure **/
void Init_struct_Tib(Typestr_Tib S, Type_Tib S_)
{
    S->Champ1 = S_.Champ1;
    S->Champ2 = S_.Champ2;
}

/** Prototypes des fonctions **/

bool Insert(Pointeur_ATib *P, int *V);
void Inorder(Pointeur_ATib *P);
void Left_branch(Pointeur_PATib *Stacknode, Pointeur_ATib *R, Pointeur_Li *T);
void Bb_lr(Pointeur_ATib *R, Pointeur_Li *T);
void Right_branch(Pointeur_PATib *Stacknode, Pointeur_ATib *R, Pointeur_Li *T);
void Bb_rl(Pointeur_ATib *R, Pointeur_Li *T);
void Leftleaves(Pointeur_ATib *R, Pointeur_Li *T);
void Ll_lr(Pointeur_ATib *R, Pointeur_Li *T);
void Rightleaves(Pointeur_ATib *R, Pointeur_Li *T);
void Ll_rl(Pointeur_ATib *R, Pointeur_Li *T);
void Resetvisited(Pointeur_ATib *R);
void Branch_lr(Pointeur_ATib *R, Pointeur_Li *H);
void Insertlist(Pointeur_Li *H, Pointeur_ATib *R);
void Printlist(Pointeur_Li *H);
void Check_branch_lr(Pointeur_ATib *R, Pointeur_Li *H);
void Deleteduplicates(Pointeur_Li *H);
void Branch_rl(Pointeur_ATib *R, Pointeur_Li *H);
void Check_branch_rl(Pointeur_ATib *R, Pointeur_Li *H);
int Isleaf(Pointeur_ATib *Node);
Pointeur_ATib Printleaves_lr(Pointeur_ATib *R, Pointeur_Li *H);
void Check_ll_lr(Pointeur_ATib *R, Pointeur_Li *H);
Pointeur_ATib Copytree(Pointeur_ATib *R);
Pointeur_ATib Printleaves_rl(Pointeur_ATib *R, Pointeur_Li *H);
void Check_ll_rl(Pointeur_ATib *R, Pointeur_Li *H);
void Cree_arb(Pointeur_ATib *R);
Pointeur_Li Creatnode(int *Data);
void Addnode(Pointeur_Li *T, int *Data);
bool Check_traversal(Pointeur_Li *T1, Pointeur_Li *T2);
bool Check_bst(Pointeur_ATib *R);

/*================================================================*/
bool Insert(Pointeur_ATib *P, int *V)
{
    /** Variables locales **/
    bool Insert2;
    Pointeur_ATib A = NULL;
    Typestr_Tib S;
    bool Bol;
    Type_Tib S_S;

    /** Corps du module **/
    S = malloc(sizeof(Type_Tib));
    Bol = True;
    if (*P == NULL)
    {
        S_S.Champ1 = *V;
        S_S.Champ2 = False;
        Init_struct_Tib(S, S_S);
        Creernoeud_ATib(&*P);
        Aff_info_ATib(*P, S);
    }
    else
    {
        if (*V == Struct1_Tib(Info_ATib(*P)))
        {
            Bol = False;
        }
        else
        {
            if (*V < Struct1_Tib(Info_ATib(*P)))
            {
                A = Fg_ATib(*P);
                Bol = Insert(&A, &*V);
                Aff_fg_ATib(*P, A);
            }
            else
            {
                A = Fd_ATib(*P);
                Bol = Insert(&A, &*V);
                Aff_fd_ATib(*P, A);
            };
        };
    };
    Insert2 = Bol;

    return Insert2;
}
/*================================================================*/
void Inorder(Pointeur_ATib *P)
{
    /** Variables locales **/
    Pointeur_ATib _Px1 = NULL;
    Pointeur_ATib _Px2 = NULL;

    /** Corps du module **/
    if (*P != NULL)
    {
        _Px1 = Fg_ATib(*P);
        Inorder(&_Px1);
        printf(" %d", Struct1_Tib(Info_ATib(*P)));
        _Px2 = Fd_ATib(*P);
        Inorder(&_Px2);
    };
}
/*================================================================*/
void Left_branch(Pointeur_PATib *Stacknode, Pointeur_ATib *R, Pointeur_Li *T)
{
    /** Variables locales **/
    Pointeur_ATib Q = NULL;
    Pointeur_ATib _Px1 = NULL;
    Pointeur_ATib _Px2 = NULL;

    /** Corps du module **/
    if (*R == NULL)
    {
        *R = NULL;
    }
    else
    {
        Empiler_PATib(&*Stacknode, *R);
        if (Fg_ATib(*R) != NULL)
        {
            _Px1 = Fg_ATib(*R);
            Left_branch(&*Stacknode, &_Px1, &*T);
        }
        else
        {
            if (Fd_ATib(*R) != NULL)
            {
                if (Fg_ATib(*R) == NULL)
                {
                    Depiler_PATib(&*Stacknode, &Q);
                };
                _Px2 = Fd_ATib(*R);
                Left_branch(&*Stacknode, &_Px2, &*T);
            };
        };
        Insertlist(&*T, &*R);
        /*ECRIRE ( STRUCT ( INFO ( *R ) , 1 ) ) ;*/
    };
}
/*================================================================*/
void Bb_lr(Pointeur_ATib *R, Pointeur_Li *T)
{
    /** Variables locales **/
    Pointeur_PATib Stack = NULL;
    Pointeur_ATib Curnt = NULL;
    Pointeur_ATib Prev = NULL;
    Pointeur_ATib V = NULL;
    Pointeur_ATib _Px1 = NULL;

    /** Corps du module **/
    Creerpile_PATib(&Stack);
    /*ECRIRE ( 'BB_LR : ' ) ;*/
    Left_branch(&Stack, &*R, &*T);
    Curnt = NULL;
    /*Prev := Curnt ;*/
    while (Pilevide_PATib(Stack) != True)
    {
        Depiler_PATib(&Stack, &Curnt);
        if ((Fd_ATib(Curnt) != NULL))
        {
            _Px1 = Fd_ATib(Curnt);
            Left_branch(&Stack, &_Px1, &*T);
        };
    };
    /*ECRIRE ( 'fin' ) ;*/
}
/*================================================================*/
void Right_branch(Pointeur_PATib *Stacknode, Pointeur_ATib *R, Pointeur_Li *T)
{
    /** Variables locales **/
    Pointeur_ATib Q = NULL;
    Pointeur_ATib _Px1 = NULL;
    Pointeur_ATib _Px2 = NULL;

    /** Corps du module **/
    if (*R == NULL)
    {
        *R = NULL;
    }
    else
    {
        Empiler_PATib(&*Stacknode, *R);
        if (Fd_ATib(*R) != NULL)
        {
            _Px1 = Fd_ATib(*R);
            Right_branch(&*Stacknode, &_Px1, &*T);
        }
        else
        {
            if (Fg_ATib(*R) != NULL)
            {
                if (Fd_ATib(*R) == NULL)
                {
                    Depiler_PATib(&*Stacknode, &Q);
                };
                _Px2 = Fg_ATib(*R);
                Right_branch(&*Stacknode, &_Px2, &*T);
            };
        };
        Insertlist(&*T, &*R);
        /*ECRIRE ( STRUCT ( INFO ( *R ) , 1 ) ) ;*/
    };
}
/*================================================================*/
void Bb_rl(Pointeur_ATib *R, Pointeur_Li *T)
{
    /** Variables locales **/
    Pointeur_PATib Stack = NULL;
    Pointeur_ATib Curnt = NULL;
    Pointeur_ATib Prev = NULL;
    Pointeur_ATib V = NULL;
    Pointeur_ATib _Px1 = NULL;

    /** Corps du module **/
    Creerpile_PATib(&Stack);
    /*ECRIRE ( 'BB_RL : ' ) ;*/
    Right_branch(&Stack, &*R, &*T);
    Curnt = NULL;
    while (Pilevide_PATib(Stack) != True)
    {
        Prev = Curnt;
        Depiler_PATib(&Stack, &Curnt);
        if ((Fg_ATib(Curnt) != NULL))
        {
            _Px1 = Fg_ATib(Curnt);
            Right_branch(&Stack, &_Px1, &*T);
        };
    };
    /*ECRIRE ( 'fin' ) ;*/
}
/*================================================================*/
void Leftleaves(Pointeur_ATib *R, Pointeur_Li *T)
{
    /** Variables locales **/
    bool Yes;
    bool Yeh;
    int _Px1;
    int _Px2;
    int _Px3;
    int _Px4;
    Pointeur_ATib _Px5 = NULL;
    Pointeur_ATib _Px6 = NULL;

    /** Corps du module **/
    Yes = True;
    Yeh = True;
    if (*R == NULL)
    {
        *R = NULL;
        Yes = False;
    }
    else
    {
        if ((Fg_ATib(*R) == NULL))
        {
            if ((Fd_ATib(*R) == NULL))
            {
                /*ECRIRE ( STRUCT ( INFO ( *R ) , 1 ) ) ;*/
                if ((Struct2_Tib(Info_ATib(*R)) == False))
                {
                    _Px1 = Struct1_Tib(Info_ATib(*R));
                    Addnode(&*T, &_Px1);
                    Aff_struct2_Tib(Info_ATib(*R), True);
                    Yeh = False;
                };
            }
            else
            {
                /*ECRIRE ( STRUCT ( INFO ( *R ) , 1 ) ) ;*/
                if ((Struct2_Tib(Info_ATib(Fd_ATib(*R))) == True) && (Struct2_Tib(Info_ATib(*R)) == False))
                {
                    _Px2 = Struct1_Tib(Info_ATib(*R));
                    Addnode(&*T, &_Px2);
                    Aff_struct2_Tib(Info_ATib(*R), True);
                    Yeh = False;
                };
            };
        }
        else
        {
            if ((Fd_ATib(*R) == NULL))
            {
                /*ECRIRE ( STRUCT ( INFO ( *R ) , 1 ) ) ;*/
                if ((Struct2_Tib(Info_ATib(Fg_ATib(*R))) == True) && (Struct2_Tib(Info_ATib(*R)) == False))
                {
                    _Px3 = Struct1_Tib(Info_ATib(*R));
                    Addnode(&*T, &_Px3);
                    Aff_struct2_Tib(Info_ATib(*R), True);
                    Yeh = False;
                };
            }
            else
            {
                /*ECRIRE ( STRUCT ( INFO ( *R ) , 1 ) ) ;*/
                if ((Struct2_Tib(Info_ATib(Fg_ATib(*R))) == True) && (Struct2_Tib(Info_ATib(Fd_ATib(*R))) == True) && (Struct2_Tib(Info_ATib(*R)) == False))
                {
                    _Px4 = Struct1_Tib(Info_ATib(*R));
                    Addnode(&*T, &_Px4);
                    Aff_struct2_Tib(Info_ATib(*R), True);
                    Yeh = False;
                };
            };
        };
    };
    if ((Yeh == True) && (Yes == True))
    {
        _Px5 = Fg_ATib(*R);
        Leftleaves(&_Px5, &*T);
        _Px6 = Fd_ATib(*R);
        Leftleaves(&_Px6, &*T);
    };
}
/*================================================================*/
void Ll_lr(Pointeur_ATib *R, Pointeur_Li *T)
{
    /** Variables locales **/
    Pointeur_ATib Curnt = NULL;

    /** Corps du module **/
    Curnt = *R;
    /*ECRIRE ( 'LL_LR:' ) ;*/
    while ((Struct2_Tib(Info_ATib(*R)) == False))
    {
        Leftleaves(&Curnt, &*T);
    };
    /*ECRIRE ( 'fin' ) ;*/
    Resetvisited(&*R);
}
/*================================================================*/
void Rightleaves(Pointeur_ATib *R, Pointeur_Li *T)
{
    /** Variables locales **/
    bool Yes;
    bool Yeh;
    int _Px1;
    int _Px2;
    int _Px3;
    int _Px4;
    Pointeur_ATib _Px5 = NULL;
    Pointeur_ATib _Px6 = NULL;

    /** Corps du module **/
    Yes = True;
    Yeh = True;
    if (*R == NULL)
    {
        *R = NULL;
        Yes = False;
    }
    else
    {
        if ((Fg_ATib(*R) == NULL))
        {
            if ((Fd_ATib(*R) == NULL))
            {
                /*ECRIRE ( STRUCT ( INFO ( *R ) , 1 ) ) ;*/
                if ((Struct2_Tib(Info_ATib(*R)) == False))
                {
                    _Px1 = Struct1_Tib(Info_ATib(*R));
                    Addnode(&*T, &_Px1);
                    Aff_struct2_Tib(Info_ATib(*R), True);
                    Yeh = False;
                };
            }
            else
            {
                /*ECRIRE ( STRUCT ( INFO ( *R ) , 1 ) ) ;*/
                if ((Struct2_Tib(Info_ATib(Fd_ATib(*R))) == True) && (Struct2_Tib(Info_ATib(*R)) == False))
                {
                    _Px2 = Struct1_Tib(Info_ATib(*R));
                    Addnode(&*T, &_Px2);
                    Aff_struct2_Tib(Info_ATib(*R), True);
                    Yeh = False;
                };
            };
        }
        else
        {
            if ((Fd_ATib(*R) == NULL))
            {
                /*ECRIRE ( STRUCT ( INFO ( *R ) , 1 ) ) ;*/
                if ((Struct2_Tib(Info_ATib(Fg_ATib(*R))) == True) && (Struct2_Tib(Info_ATib(*R)) == False))
                {
                    _Px3 = Struct1_Tib(Info_ATib(*R));
                    Addnode(&*T, &_Px3);
                    Aff_struct2_Tib(Info_ATib(*R), True);
                    Yeh = False;
                };
            }
            else
            {
                /*ECRIRE ( STRUCT ( INFO ( *R ) , 1 ) ) ;*/
                if ((Struct2_Tib(Info_ATib(Fg_ATib(*R))) == True) && (Struct2_Tib(Info_ATib(Fd_ATib(*R))) == True) && (Struct2_Tib(Info_ATib(*R)) == False))
                {
                    _Px4 = Struct1_Tib(Info_ATib(*R));
                    Addnode(&*T, &_Px4);
                    Aff_struct2_Tib(Info_ATib(*R), True);
                    Yeh = False;
                };
            };
        };
    };
    if ((Yeh == True) && (Yes == True))
    {
        _Px5 = Fd_ATib(*R);
        Rightleaves(&_Px5, &*T);
        _Px6 = Fg_ATib(*R);
        Rightleaves(&_Px6, &*T);
    };
}
/*================================================================*/
void Ll_rl(Pointeur_ATib *R, Pointeur_Li *T)
{
    /** Variables locales **/
    Pointeur_ATib Curnt = NULL;

    /** Corps du module **/
    Curnt = *R;
    /*ECRIRE ( 'LL_RL:' ) ;*/
    while (Struct2_Tib(Info_ATib(*R)) == False)
    {
        Rightleaves(&Curnt, &*T);
    };
    /*ECRIRE ( 'fin' ) ;*/
    Resetvisited(&*R);
}
/*================================================================*/
void Resetvisited(Pointeur_ATib *R)
{
    /** Variables locales **/
    Pointeur_ATib _Px1 = NULL;
    Pointeur_ATib _Px2 = NULL;

    /** Corps du module **/
    if (*R == NULL)
    {
        *R = NULL;
    }
    else
    {
        Aff_struct2_Tib(Info_ATib(*R), False);
        _Px1 = Fg_ATib(*R);
        Resetvisited(&_Px1);
        _Px2 = Fd_ATib(*R);
        Resetvisited(&_Px2);
    };
}
/*================================================================*/
void Branch_lr(Pointeur_ATib *R, Pointeur_Li *H)
{
    /** Variables locales **/
    Pointeur_ATib _Px1 = NULL;
    Pointeur_ATib _Px2 = NULL;
    Pointeur_ATib _Px3 = NULL;

    /** Corps du module **/
    if (*R == NULL)
    {
        *R = NULL;
    }
    else
    {
        if ((Fg_ATib(*R) != NULL))
        {
            if ((Struct2_Tib(Info_ATib(Fg_ATib(*R))) == False))
            {
                _Px1 = Fg_ATib(*R);
                Branch_lr(&_Px1, &*H);
            }
            else
            {
                if (Fd_ATib(*R) != NULL)
                {
                    if ((Struct2_Tib(Info_ATib(Fd_ATib(*R))) == False))
                    {
                        _Px2 = Fd_ATib(*R);
                        Branch_lr(&_Px2, &*H);
                    };
                };
            };
        }
        else
        {
            if (Fd_ATib(*R) != NULL)
            {
                if ((Struct2_Tib(Info_ATib(Fd_ATib(*R))) == False))
                {
                    _Px3 = Fd_ATib(*R);
                    Branch_lr(&_Px3, &*H);
                };
            };
        };
        Insertlist(&*H, &*R);
        if ((Fg_ATib(*R) == NULL))
        {
            if (Fd_ATib(*R) == NULL)
            {
                Aff_struct2_Tib(Info_ATib(*R), True);
            }
            else
            {
                if (Struct2_Tib(Info_ATib(Fd_ATib(*R))) == True)
                {
                    Aff_struct2_Tib(Info_ATib(*R), True);
                };
            };
        }
        else
        {
            if (Struct2_Tib(Info_ATib(Fg_ATib(*R))) == True)
            {
                if (Fd_ATib(*R) == NULL)
                {
                    Aff_struct2_Tib(Info_ATib(*R), True);
                }
                else
                {
                    if (Struct2_Tib(Info_ATib(Fd_ATib(*R))) == True)
                    {
                        Aff_struct2_Tib(Info_ATib(*R), True);
                    };
                };
            };
        };
    };
}
/*================================================================*/
void Insertlist(Pointeur_Li *H, Pointeur_ATib *R)
{
    /** Variables locales **/
    Pointeur_Li New = NULL;
    Pointeur_Li Temp = NULL;

    /** Corps du module **/
    Allouer_Li(&New);
    Aff_val_Li(New, Struct1_Tib(Info_ATib(*R)));
    Aff_adr_Li(New, NULL);
    if (*H == NULL)
    {
        *H = New;
    }
    else
    {
        Temp = *H;
        while (Suivant_Li(Temp) != NULL)
        {
            Temp = Suivant_Li(Temp);
        };
        Aff_adr_Li(Temp, New);
    };
}
/*================================================================*/
void Printlist(Pointeur_Li *H)
{
    /** Variables locales **/
    Pointeur_Li Temp = NULL;

    /** Corps du module **/
    Temp = *H;
    while ((Temp != NULL))
    {
        ;
        printf("%d->", Valeur_Li(Temp));
        Temp = Suivant_Li(Temp);
    };
    printf("end;");
}
/*================================================================*/
void Check_branch_lr(Pointeur_ATib *R, Pointeur_Li *H)
{

    /** Corps du module **/
    while (Struct2_Tib(Info_ATib(*R)) != True)
    {
        Branch_lr(&*R, &*H);
    };
    /*ECRIRE ( 'the final result of LR is : ' ) ;*/
    Deleteduplicates(&*H);
    /*APPEL Printlist ( *H ) ;*/
    Resetvisited(&*R);
}
/*================================================================*/
void Deleteduplicates(Pointeur_Li *H)
{
    /** Variables locales **/
    Pointeur_Li Current = NULL;
    Pointeur_Li Runner = NULL;
    Pointeur_Li Temp = NULL;
    bool Block1;

    /** Corps du module **/
    Block1 = True;
    if ((*H == NULL))
    {
        Block1 = False;
    }
    else
    {
        if ((Suivant_Li(*H) == NULL))
        {
            Block1 = False;
        };
    };
    if (Block1)
    {
        Current = *H;
        while (Current != NULL)
        {
            Runner = Current;
            while ((Suivant_Li(Runner) != NULL))
            {
                if (Valeur_Li(Suivant_Li(Runner)) == Valeur_Li(Current))
                {
                    Temp = Suivant_Li(Runner);
                    Aff_adr_Li(Runner, Suivant_Li(Temp));
                    Liberer_Li(Temp);
                }
                else
                {
                    Runner = Suivant_Li(Runner);
                };
            };
            Current = Suivant_Li(Current);
        };
    };
}
/*================================================================*/
void Branch_rl(Pointeur_ATib *R, Pointeur_Li *H)
{
    /** Variables locales **/
    Pointeur_ATib _Px1 = NULL;
    Pointeur_ATib _Px2 = NULL;
    Pointeur_ATib _Px3 = NULL;

    /** Corps du module **/
    if (*R == NULL)
    {
        *R = NULL;
    }
    else
    {
        if ((Fd_ATib(*R) != NULL))
        {
            if ((Struct2_Tib(Info_ATib(Fd_ATib(*R))) == False))
            {
                _Px1 = Fd_ATib(*R);
                Branch_rl(&_Px1, &*H);
            }
            else
            {
                if (Fg_ATib(*R) != NULL)
                {
                    if ((Struct2_Tib(Info_ATib(Fg_ATib(*R))) == False))
                    {
                        _Px2 = Fg_ATib(*R);
                        Branch_rl(&_Px2, &*H);
                    };
                };
            };
        }
        else
        {
            if (Fg_ATib(*R) != NULL)
            {
                if ((Struct2_Tib(Info_ATib(Fg_ATib(*R))) == False))
                {
                    _Px3 = Fg_ATib(*R);
                    Branch_rl(&_Px3, &*H);
                };
            };
        };
        Insertlist(&*H, &*R);
        if ((Fd_ATib(*R) == NULL))
        {
            if (Fg_ATib(*R) == NULL)
            {
                Aff_struct2_Tib(Info_ATib(*R), True);
            }
            else
            {
                if (Struct2_Tib(Info_ATib(Fg_ATib(*R))) == True)
                {
                    Aff_struct2_Tib(Info_ATib(*R), True);
                };
            };
        }
        else
        {
            if (Struct2_Tib(Info_ATib(Fd_ATib(*R))) == True)
            {
                if (Fg_ATib(*R) == NULL)
                {
                    Aff_struct2_Tib(Info_ATib(*R), True);
                }
                else
                {
                    if (Struct2_Tib(Info_ATib(Fg_ATib(*R))) == True)
                    {
                        Aff_struct2_Tib(Info_ATib(*R), True);
                    };
                };
            };
        };
    };
}
/*================================================================*/
void Check_branch_rl(Pointeur_ATib *R, Pointeur_Li *H)
{

    /** Corps du module **/
    while (Struct2_Tib(Info_ATib(*R)) != True)
    {
        Branch_rl(&*R, &*H);
    };
    /*ECRIRE ( 'the final result of RL is : ' ) ;*/
    Deleteduplicates(&*H);
    /*APPEL Printlist ( *H ) ;*/
    Resetvisited(&*R);
}
/*================================================================*/
int Isleaf(Pointeur_ATib *Node)
{
    /** Variables locales **/
    int Isleaf2;

    /** Corps du module **/
    if (*Node == NULL)
    {
        Isleaf2 = 0;
    }
    else
    {
        if ((Fg_ATib(*Node) == NULL) && (Fd_ATib(*Node) == NULL))
        {
            ;
            Isleaf2 = 1;
        }
        else
        {
            Isleaf2 = 0;
        };
    };

    return Isleaf2;
}
/*================================================================*/
Pointeur_ATib Printleaves_lr(Pointeur_ATib *R, Pointeur_Li *H)
{
    /** Variables locales **/
    Pointeur_ATib Printleaves_lr2 = NULL;
    int _Px1;
    Pointeur_ATib _Px2 = NULL;
    Pointeur_ATib _Px3 = NULL;

    /** Corps du module **/
    if (*R == NULL)
    {
        Printleaves_lr2 = NULL;
    }
    else
    {
        /*ECRIRE ( STRUCT ( INFO ( *R ) , 1 ) ) ;*/
        if (Isleaf(&*R) == 1)
        {
            _Px1 = Struct1_Tib(Info_ATib(*R));
            Addnode(&*H, &_Px1);
            Printleaves_lr2 = NULL;
        }
        else
        {
            _Px2 = Fg_ATib(*R);
            Aff_fg_ATib(*R, Printleaves_lr(&_Px2, &*H));
            _Px3 = Fd_ATib(*R);
            Aff_fd_ATib(*R, Printleaves_lr(&_Px3, &*H));
            Printleaves_lr2 = *R;
        };
    };

    return Printleaves_lr2;
}
/*================================================================*/
void Check_ll_lr(Pointeur_ATib *R, Pointeur_Li *H)
{
    /** Variables locales **/
    Pointeur_ATib A = NULL;

    /** Corps du module **/
    A = *R;
    while (A != NULL)
    {
        A = Printleaves_lr(&A, &*H);
    };
}
/*================================================================*/
Pointeur_ATib Copytree(Pointeur_ATib *R)
{
    /** Variables locales **/
    Pointeur_ATib Copytree2 = NULL;
    Pointeur_ATib Newroot = NULL;
    Typestr_Tib S;
    Type_Tib S_S;
    Pointeur_ATib _Px1 = NULL;
    Pointeur_ATib _Px2 = NULL;

    /** Corps du module **/
    S = malloc(sizeof(Type_Tib));
    if (*R == NULL)
    {
        Copytree2 = NULL;
    }
    else
    {
        S_S.Champ1 = Struct1_Tib(Info_ATib(*R));
        S_S.Champ2 = Struct2_Tib(Info_ATib(*R));
        Init_struct_Tib(S, S_S);
        Creernoeud_ATib(&Newroot);
        Aff_info_ATib(Newroot, S);
        _Px1 = Fg_ATib(*R);
        Aff_fg_ATib(Newroot, Copytree(&_Px1));
        _Px2 = Fd_ATib(*R);
        Aff_fd_ATib(Newroot, Copytree(&_Px2));
        Copytree2 = Newroot;
    };

    return Copytree2;
}
/*================================================================*/
Pointeur_ATib Printleaves_rl(Pointeur_ATib *R, Pointeur_Li *H)
{
    /** Variables locales **/
    Pointeur_ATib Printleaves_rl2 = NULL;
    int _Px1;
    Pointeur_ATib _Px2 = NULL;
    Pointeur_ATib _Px3 = NULL;

    /** Corps du module **/
    if (*R == NULL)
    {
        Printleaves_rl2 = NULL;
    }
    else
    {
        /*ECRIRE ( STRUCT ( INFO ( *R ) , 1 ) ) ;*/
        if (Isleaf(&*R) == 1)
        {
            _Px1 = Struct1_Tib(Info_ATib(*R));
            Addnode(&*H, &_Px1);
            Printleaves_rl2 = NULL;
        }
        else
        {
            _Px2 = Fd_ATib(*R);
            Aff_fd_ATib(*R, Printleaves_rl(&_Px2, &*H));
            _Px3 = Fg_ATib(*R);
            Aff_fg_ATib(*R, Printleaves_rl(&_Px3, &*H));
            Printleaves_rl2 = *R;
        };
    };

    return Printleaves_rl2;
}
/*================================================================*/
void Check_ll_rl(Pointeur_ATib *R, Pointeur_Li *H)
{
    /** Variables locales **/
    Pointeur_ATib Q = NULL;

    /** Corps du module **/
    Q = *R;
    while (Q != NULL)
    {
        Q = Printleaves_rl(&Q, &*H);
    };
}
/*================================================================*/
void Cree_arb(Pointeur_ATib *R)
{
    /** Variables locales **/
    int I;
    int A;
    bool Bol;

    /** Corps du module **/
    Bol = True;
    *R = NULL;
    I = 0;
    A = Aleanombre(100);
    Bol = Insert(&*R, &A);
    Bol = False;
    while (I < 99)
    {
        while (Bol != True)
        {
            A = Aleanombre(100);
            Bol = Insert(&*R, &A);
        };
        Bol = False;
        I = I + 1;
    };
}
/*================================================================*/
Pointeur_Li Creatnode(int *Data)
{
    /** Variables locales **/
    Pointeur_Li Creatnode2 = NULL;
    Pointeur_Li Node = NULL;

    /** Corps du module **/
    Allouer_Li(&Node);
    Aff_val_Li(Node, *Data);
    Aff_adr_Li(Node, NULL);
    Creatnode2 = Node;

    return Creatnode2;
}
/*================================================================*/
void Addnode(Pointeur_Li *T, int *Data)
{
    /** Variables locales **/
    Pointeur_Li Temp = NULL;
    Pointeur_Li Node = NULL;

    /** Corps du module **/
    Node = Creatnode(&*Data);
    if (*T == NULL)
    {
        *T = Node;
    }
    else
    {
        Temp = *T;
        while (Suivant_Li(Temp) != NULL)
        {
            Temp = Suivant_Li(Temp);
        };
        Aff_adr_Li(Temp, Node);
    };
}
/*================================================================*/
bool Check_traversal(Pointeur_Li *T1, Pointeur_Li *T2)
{
    /** Variables locales **/
    bool Check_traversal2;
    bool Done;

    /** Corps du module **/
    Done = True;
    while (((*T1 != NULL) || (*T2 != NULL)) && (Done == True))
    {
        if (Valeur_Li(*T1) == Valeur_Li(*T2))
        {
            *T1 = Suivant_Li(*T1);
            *T2 = Suivant_Li(*T2);
        }
        else
        {
            Done = False;
        };
    };
    Check_traversal2 = Done;

    return Check_traversal2;
}
/*================================================================*/
bool Check_bst(Pointeur_ATib *R)
{
    /** Variables locales **/
    bool Check_bst2;
    bool Checkd;
    bool Checkg;
    Pointeur_ATib _Px1 = NULL;
    Pointeur_ATib _Px2 = NULL;

    /** Corps du module **/
    Check_bst2 = True;
    if (*R != NULL)
    {
        if ((Fg_ATib(*R) == NULL) && (Fd_ATib(*R) == NULL))
        {
            Check_bst2 = True;
        }
        else
        {
            if (Fd_ATib(*R) == NULL)
            {
                if ((Struct1_Tib(Info_ATib(*R)) > Struct1_Tib(Info_ATib(Fg_ATib(*R)))))
                {
                    Check_bst2 = True;
                };
            }
            else
            {
                if (Fg_ATib(*R) == NULL)
                {
                    if ((Struct1_Tib(Info_ATib(*R)) < Struct1_Tib(Info_ATib(Fd_ATib(*R)))))
                    {
                        Check_bst2 = True;
                    };
                }
                else
                {
                    if ((Struct1_Tib(Info_ATib(*R)) > Struct1_Tib(Info_ATib(Fg_ATib(*R)))) && (Struct1_Tib(Info_ATib(*R)) < Struct1_Tib(Info_ATib(Fd_ATib(*R)))))
                    {
                        Check_bst2 = True;
                    }
                    else
                    {
                        Check_bst2 = False;
                    };
                };
            };
        };
        _Px1 = Fd_ATib(*R);
        _Px2 = Fg_ATib(*R);
        Check_bst2 = (Check_bst(&_Px1)) && (Check_bst(&_Px2));
    };

    return Check_bst2;
}

//===============================================================animation=======================================================================

void page_acceuil()
{
    system("Cls"); // Effacer l'ecran
    int k;
    for (k = 0; k < 10; k++)
    {                   // Afficher 10 fois le logo de ESI
        if (k % 2 == 0) // Les iterations paires s'afficherent en vert
            system("color 0A");
        if (k % 2 == 1) // Les iterations impaires s'afficherent en ciane
            system("color 0B");

        printf("\n\n\n\n\n\n"); // imprimer le logo de ESI
        printf(
            "\t\t\t\t                                              iiii\n"
            "\t\t\t\t                                             i::::i\n"
            "\t\t\t\t                                              iiii\n\n"
            "\t\t\t\t        eeeeeeeeeeee          ssssssssss    iiiiiii\n"
            "\t\t\t\t      ee::::::::::::ee      ss::::::::::s   i:::::i\n"
            "\t\t\t\t     e::::::eeeee:::::ee  ss:::::::::::::s   i::::i\n"
            "\t\t\t\t    e::::::e     e:::::e  s::::::ssss:::::s  i::::i\n"
            "\t\t\t\t    e:::::::eeeee::::::e   s:::::s  ssssss   i::::i\n"
            "\t\t\t\t    e:::::::::::::::::e      s::::::s        i::::i\n"
            "\t\t\t\t    e::::::eeeeeeeeeee          s::::::s     i::::i\n"
            "\t\t\t\t    e:::::::e             ssssss   s:::::s   i::::i\n"
            "\t\t\t\t    e::::::::e            s:::::ssss::::::s i::::::i\n"
            "\t\t\t\t     e::::::::eeeeeeee    s::::::::::::::s  i::::::i\n"
            "\t\t\t\t      ee:::::::::::::e     s:::::::::::ss   i::::::i\n"
            "\t\t\t\t        eeeeeeeeeeeeee      sssssssssss     iiiiiiii\n");

        Sleep(200); // Attendre 200 ms (0,2 s) a chaque iteration
        system("cls");
    }

    system("cls"); // effacer l'ecran
    printf("\t\t\t\033[96m           R%cpublique Alg%crienne D%cmocratique et Populaire           \033[0m\n", 130, 130, 130);
    printf("\t\t\t\033[96m  Minist%cre de l'Enseignement Sup%crieur et de la Recherche Scientifique\033[0m\n", 130, 130);
    printf("\t\t\t      \033[96m _______________________________________________________\n");
    printf("\t\t\t      \033[96m|        \033[92m_______\033[0m    \033[91m _______\033[0m    \033[97m _\033[0m                      \033[96m|\n");
    printf("\t\t\t      \033[96m|       \033[92m|  _____|\033[0m   \033[91m|  _____|\033[0m   \033[97m| |\033[0m  \033[92m%ccole nationale\033[0m    \033[96m|\n", 130);
    printf("\t\t\t      \033[96m|       \033[92m| |_____\033[0m    \033[91m| |_____\033[0m    \033[97m| |\033[0m                     \033[96m|\n");
    printf("\t\t\t      \033[96m|       \033[92m|  _____|\033[0m   \033[91m|_____  |\033[0m   \033[97m| |\033[0m  \033[91msup%crieure\033[0m         \033[96m|\n", 130);
    printf("\t\t\t      \033[96m|       \033[92m| |_____\033[0m    \033[91m _____| |\033[0m   \033[97m| |\033[0m                     \033[96m|\n");
    printf("\t\t\t      \033[96m|       \033[92m|_______|\033[0m   \033[91m|_______|\033[0m   \033[97m|_|\033[0m  \033[97md'informatique\033[0m     \033[96m|\n");
    printf("\t\t\t      \033[96m|_______________________________________________________|\033[0m\n\n");

    printf("\t\t\t\t\033[96m  CPI - 1%cre Ann%ce - Ann%ce Universitaire 2023/2024 \n", 138, 130, 130);
    printf("\t\t\t\033[96m ___________________________________________________________________\n");
    printf("\t\t\t\033[96m|                                                                   |\n");
    printf("\t\t\t\033[96m|     REALISEd by  :  \033[97mBendifallah rami\033[96m                              |\n");
    printf("\t\t\t\033[96m|                              &                                    |\n");
    printf("\t\t\t\033[96m|                          \033[97mbenkradidja Rayane\033[96m                       |\n");
    printf("\t\t\t\033[96m|                                                                   |\n");
    printf("\t\t\t\033[96m|                                                                   |\n");
    printf("\t\t\t\033[96m|               SECTION :  \033[97mA, B\033[96m          GROUPE: \033[97m02, 05\033[96m             |\n");
    printf("\t\t\t\033[96m|                                                                   |\n");
    printf("\t\t\t\033[96m|             TP2 :  \033[97m### Tree traversal methods ##\033[96m                  |\n");
    printf("\t\t\t\033[96m|                                                                   |\n");
    printf("\t\t\t\033[96m|                                                                   |\n");
    printf("\t\t\t\033[96m|___________________________________________________________________|\n\n\n");

    printf("\t\t\t                            \033[91mS'il vous plait                                 \n");
    printf("\t\t\t          Appuyez sur n'importe quelle touche pour continuer...\033[0m               ");
    getchar();

    system("cls");
}

//-----------------------------------------------//-----------------------------------------------//

void page_chargement()
{

    /*
    Le principe est simple on va juste afficher la barre avec le pourcentage
    et puis effacer l'ecran et reafficher la barre suivante
    */

    system("cls");

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");

    printf("\t\t\t\t|||                                                 5%%  ");
    Sleep(300);
    system("cls");

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t|||||                                               20%%  ");
    Sleep(300);
    system("cls");

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t||||||||||||||||                                    30%%  ");
    Sleep(300);
    system("cls");

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t|||||||||||||||||||||||||                           45%%  ");
    Sleep(300);
    system("cls");

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t|||||||||||||||||||||||||||||||                     60%%  ");
    Sleep(300);
    system("cls");

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t||||||||||||||||||||||||||||||||||||||||            80%%  ");
    Sleep(300);
    system("cls");

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t||||||||||||||||||||||||||||||||||||||||||||||||||  100%% ");
    system("cls");
}
//=====================================================================end of loading page==============================================================

void welcome()
{
    printf(".--.\n");
    printf(" /  \\\n");
    printf("/ _  \\\n");
    printf("( o.o )\n");
    printf(" \\___/\n");
    printf("  / \\ \n");
    printf(" /   \\ \n");
    printf("/     \\ \n");
    printf("/       \\ \n");
    printf(" *---------*\n");
    printf("\n");
    printf("\n");
    printf("\n");
}
//==================================================================end of some drawing================================================

void menu()
{
    // Main menu
    system("cls");
    printf("   \033[1;36m"); // Set text color to bold cyan
    printf("   \t\t\t\t\t=========================================================\n");
    printf("   \t\t\t\t\t|                      \033[1;32m  MAIN MENU\033[0m                       |\n"); // Set text color to bold green for menu title
    printf("   \t\t\t\t\t=========================================================\n");
    printf("   \t\t\t\t\t|  \033[1;32m1.\033[0m Create 10 trees and check correctness              |\n"); // Set text color to bold green for menu option numbers
    printf("   \t\t\t\t\t|  \033[1;32m2.\033[0m Traverse the tree with traversal methods           |\n");
    printf("   \t\t\t\t\t|  \033[1;32m3.\033[0m Simulate branch by branch from left to right       |\n");
    printf("   \t\t\t\t\t|  \033[1;32m4.\033[0m Simulate branch by branch from left to right       |\n");
    printf("   \t\t\t\t\t|  \033[1;32m5.\033[0m Simulate leaf by leaf from left to right           |\n");
    printf("   \t\t\t\t\t|  \033[1;32m6.\033[0m Simulate leaf by leaf from right to left           |\n");
    printf("   \t\t\t\t\t|  \033[1;32m7.\033[0m exit program                                       |\n");
    printf("   \t\t\t\t\t=========================================================\n\n");
    printf("\033[0m"); // Reset text color to default
    printf("\n");
}

void menu_traversels()
{
    system("cls");
    printf("   \033[1;36m"); // Set text color to bold cyan
    printf("   \t\t\t\t\t=========================================================\n");
    printf("   \t\t\t\t\t|                      \033[1;32m  TRAVERSAL MENU\033[0m                  |\n"); // Set text color to bold green for menu title
    printf("   \t\t\t\t\t=========================================================\n");
    printf("   \t\t\t\t\t|  \033[1;32m1.\033[0m Branch by branch from left to right                |\n");
    printf("   \t\t\t\t\t|  \033[1;32m2.\033[0m Branch by branch from right to left                |\n");
    printf("   \t\t\t\t\t|  \033[1;32m3.\033[0m Leaf by leaf from left to right                    |\n");
    printf("   \t\t\t\t\t|  \033[1;32m4.\033[0m Leaf by leaf from right to left                    |\n");
    printf("   \t\t\t\t\t|  \033[1;32m5.\033[0m Return to Main Menu                                |\n");
    printf("   \t\t\t\t\t=========================================================\n\n");
    printf("\033[0m"); // Reset text color to default
    printf("\n");
}

//==================================================================end of the Menu===============================================

//===========================================================testprint===============================================================
void testprint()
{
    printf("          50\n");
    printf("        /    \\\n");
    printf("      /        \\\n");
    printf("    /            \\\n");
    printf("   25            75\n");
    printf("  /  \\          /  \\\n");
    printf(" /    \\        /    \\\n");
    printf("12    37      62    87\n");
    printf("/ \\   /                  \n");
    printf("6 18 31                \n");
    printf("\t\t\t\t\t\t\t start");
}

void testprint1()
{
    const char *green = "\033[0;32m";
    const char *reset = "\033[0m";

    printf("          50\n");
    printf("        /    \\\n");
    printf("      /        \\\n");
    printf("    /            \\\n");
    printf("   25            75\n");
    printf("  /  \\          /  \\\n");
    printf(" /    \\        /    \\\n");
    printf("12    37      62    87\n");
    printf("/ \\   /                  \n");
    printf("%s6%s 18 31\n", green, reset);
    printf("\t\t\t\t\t\t\t 6->");
}
void testprint2()
{
    const char *green = "\033[0;32m";
    const char *reset = "\033[0m";

    printf("          50\n");
    printf("        /    \\\n");
    printf("      /        \\\n");
    printf("    /            \\\n");
    printf("   25            75\n");
    printf("  /  \\          /  \\\n");
    printf(" /    \\        /    \\\n");
    printf("%s12%s    37      62    87\n", green, reset);
    printf("/ \\   /                  \n");
    printf("%s6%s 18 31\n", green, reset);
    printf("\t\t\t\t\t\t\t 6->12->");
}

void testprint3()
{
    const char *green = "\033[0;32m";
    const char *reset = "\033[0m";

    printf("          50\n");
    printf("        /    \\\n");
    printf("      /        \\\n");
    printf("    /            \\\n");
    printf("   %s25%s            75\n", green, reset);
    printf("  /  \\          /  \\\n");
    printf(" /    \\        /    \\\n");
    printf("%s12%s    37      62    87\n", green, reset);
    printf("/ \\   /                  \n");
    printf("%s6%s 18 31\n", green, reset);
    printf("\t\t\t\t\t\t\t 6->12->25->");
}

void testprint4()
{
    const char *green = "\033[0;32m";
    const char *reset = "\033[0m";

    printf("          %s50%s\n", green, reset);
    printf("        /    \\\n");
    printf("      /        \\\n");
    printf("    /            \\\n");
    printf("   %s25%s            75\n", green, reset);
    printf("  /  \\          /  \\\n");
    printf(" /    \\        /    \\\n");
    printf("%s12%s    37      62    87\n", green, reset);
    printf("/ \\   /                  \n");
    printf("%s6%s 18 31\n", green, reset);
    printf("\t\t\t\t\t\t\t 6->12->25->50->");
}

void testprint5()
{
    const char *green = "\033[0;32m";
    const char *reset = "\033[0m";

    printf("          %s50%s\n", green, reset);
    printf("        /    \\\n");
    printf("      /        \\\n");
    printf("    /            \\\n");
    printf("   %s25%s            75\n", green, reset);
    printf("  /  \\          /  \\\n");
    printf(" /    \\        /    \\\n");
    printf("%s12%s    37      62    87\n", green, reset);
    printf("/ \\   /                  \n");
    printf("%s6%s %s18%s 31\n", green, reset, green, reset);
    printf("\t\t\t\t\t\t\t 6->12->25->50->18");
}

void testprint6()
{
    const char *green = "\033[0;32m";
    const char *reset = "\033[0m";

    printf("          %s50%s\n", green, reset);
    printf("        /    \\\n");
    printf("      /        \\\n");
    printf("    /            \\\n");
    printf("   %s25%s            75\n", green, reset);
    printf("  /  \\          /  \\\n");
    printf(" /    \\        /    \\\n");
    printf("%s12%s    37      62    87\n", green, reset);
    printf("/ \\   /                  \n");
    printf("%s6%s %s18%s %s31%s\n", green, reset, green, reset, green, reset);
    printf("\t\t\t\t\t\t\t 6->12->25->50->18->31->");
}

void testprint7()
{
    const char *green = "\033[0;32m";
    const char *reset = "\033[0m";

    printf("          %s50%s\n", green, reset);
    printf("        /    \\\n");
    printf("      /        \\\n");
    printf("    /            \\\n");
    printf("   %s25%s            75\n", green, reset);
    printf("  /  \\          /  \\\n");
    printf(" /    \\        /    \\\n");
    printf("%s12%s    %s37%s      62    87\n", green, reset, green, reset);
    printf("/ \\   /                  \n");
    printf("%s6%s %s18%s %s31%s\n", green, reset, green, reset, green, reset);
    printf("\t\t\t\t\t\t\t 6->12->25->50->18->31->37->");
}

void testprint8()
{
    const char *green = "\033[0;32m";
    const char *reset = "\033[0m";

    printf("          %s50%s\n", green, reset);
    printf("        /    \\\n");
    printf("      /        \\\n");
    printf("    /            \\\n");
    printf("   %s25%s            75\n", green, reset);
    printf("  /  \\          /  \\\n");
    printf(" /    \\        /    \\\n");
    printf("%s12%s    %s37%s      %s62%s    87\n", green, reset, green, reset, green, reset);
    printf("/ \\   /                  \n");
    printf("%s6%s %s18%s %s31%s\n", green, reset, green, reset, green, reset);
    printf("\t\t\t\t\t\t\t 6->12->25->50->18->31->37->62");
}

void testprint9()
{
    const char *green = "\033[0;32m";
    const char *reset = "\033[0m";

    printf("          %s50%s\n", green, reset);
    printf("        /    \\\n");
    printf("      /        \\\n");
    printf("    /            \\\n");
    printf("   %s25%s            %s75%s\n", green, reset, green, reset);
    printf("  /  \\          /  \\\n");
    printf(" /    \\        /    \\\n");
    printf("%s12%s    %s37%s      %s62%s    87\n", green, reset, green, reset, green, reset);
    printf("/ \\   /                  \n");
    printf("%s6%s %s18%s %s31%s\n", green, reset, green, reset, green, reset);
    printf("\t\t\t\t\t\t\t 6->12->25->50->18->31->37->62->75");
}

void testprint10()
{
    const char *green = "\033[0;32m";
    const char *reset = "\033[0m";

    printf("          %s50%s\n", green, reset);
    printf("        /    \\\n");
    printf("      /        \\\n");
    printf("    /            \\\n");
    printf("   %s25%s            %s75%s\n", green, reset, green, reset);
    printf("  /  \\          /  \\\n");
    printf(" /    \\        /    \\\n");
    printf("%s12%s    %s37%s      %s62%s    %s87%s\n", green, reset, green, reset, green, reset, green, reset);
    printf("/ \\   /                  \n");
    printf("%s6%s %s18%s %s31%s\n", green, reset, green, reset, green, reset);
    printf("\t\t\t\t\t\t\t 6->12->25->50->18->31->37->62->75->87->end");
}
//===========================================================testprint===============================================================

void leaf_LR_print1()
{
    const char *green = "\033[0;32m";
    const char *reset = "\033[0m";

    printf("          50\n");
    printf("        /    \\\n");
    printf("      /        \\\n");
    printf("    /            \\\n");
    printf("   25            75\n");
    printf("  /  \\          /  \\\n");
    printf(" /    \\        /    \\\n");
    printf("12    37      62    87\n");
    printf("/ \\   /                  \n");
    printf("%s6%s 18 31\n", green, reset);
    printf("\t\t\t\t\t\t\t 6->");
}

void leaf_LR_print2()
{
    const char *green = "\033[0;32m";
    const char *reset = "\033[0m";

    printf("          50\n");
    printf("        /    \\\n");
    printf("      /        \\\n");
    printf("    /            \\\n");
    printf("   25            75\n");
    printf("  /  \\          /  \\\n");
    printf(" /    \\        /    \\\n");
    printf("12    37      62    87\n");
    printf("/ \\   /                  \n");
    printf("%s6%s %s18%s 31\n", green, reset, green, reset);
    printf("\t\t\t\t\t\t\t 6->18->");
}

void leaf_LR_print3()
{
    const char *green = "\033[0;32m";
    const char *reset = "\033[0m";

    printf("          50\n");
    printf("        /    \\\n");
    printf("      /        \\\n");
    printf("    /            \\\n");
    printf("   25            75\n");
    printf("  /  \\          /  \\\n");
    printf(" /    \\        /    \\\n");
    printf("12    37      62    87\n");
    printf("/ \\   /                  \n");
    printf("%s6%s %s18%s %s31%s\n", green, reset, green, reset, green, reset);
    printf("\t\t\t\t\t\t\t 6->18->31->");
}

void leaf_LR_print4()
{
    const char *green = "\033[0;32m";
    const char *reset = "\033[0m";

    printf("          50\n");
    printf("        /    \\\n");
    printf("      /        \\\n");
    printf("    /            \\\n");
    printf("   25            75\n");
    printf("  /  \\          /  \\\n");
    printf(" /    \\        /    \\\n");
    printf("12    37      %s62%s    87\n", green, reset);
    printf("/ \\   /                  \n");
    printf("%s6%s %s18%s %s31%s\n", green, reset, green, reset, green, reset);
    printf("\t\t\t\t\t\t\t 6->18->31->62->");
}

void leaf_LR_print5()
{
    const char *green = "\033[0;32m";
    const char *reset = "\033[0m";

    printf("          50\n");
    printf("        /    \\\n");
    printf("      /        \\\n");
    printf("    /            \\\n");
    printf("   25            75\n");
    printf("  /  \\          /  \\\n");
    printf(" /    \\        /    \\\n");
    printf("12    37      %s62%s    %s87%s\n", green, reset, green, reset);
    printf("/ \\   /                  \n");
    printf("%s6%s %s18%s %s31%s\n", green, reset, green, reset, green, reset);
    printf("\t\t\t\t\t\t\t 6->18->31->62->87->");
}

void leaf_LR_print6()
{
    const char *green = "\033[0;32m";
    const char *reset = "\033[0m";

    printf("          50\n");
    printf("        /    \\\n");
    printf("      /        \\\n");
    printf("    /            \\\n");
    printf("   25            75\n");
    printf("  /  \\          /  \\\n");
    printf(" /    \\        /    \\\n");
    printf("%s12%s    37      %s62%s    %s87%s\n", green, reset, green, reset, green, reset);
    printf("/ \\   /                  \n");
    printf("%s6%s %s18%s %s31%s\n", green, reset, green, reset, green, reset);
    printf("\t\t\t\t\t\t\t 6->18->31->62->87->12->");
}

void leaf_LR_print7()
{
    const char *green = "\033[0;32m";
    const char *reset = "\033[0m";

    printf("          50\n");
    printf("        /    \\\n");
    printf("      /        \\\n");
    printf("    /            \\\n");
    printf("   25            75\n");
    printf("  /  \\          /  \\\n");
    printf(" /    \\        /    \\\n");
    printf("%s12%s    %s37%s      %s62%s    %s87%s\n", green, reset, green, reset, green, reset, green, reset);
    printf("/ \\   /                  \n");
    printf("%s6%s %s18%s %s31%s\n", green, reset, green, reset, green, reset);
    printf("\t\t\t\t\t\t\t 6->18->31->62->87->12->37->");
}

void leaf_LR_print8()
{
    const char *green = "\033[0;32m";
    const char *reset = "\033[0m";

    printf("          50\n");
    printf("        /    \\\n");
    printf("      /        \\\n");
    printf("    /            \\\n");
    printf("   %s25%s            75\n", green, reset);
    printf("  /  \\          /  \\\n");
    printf(" /    \\        /    \\\n");
    printf("%s12%s    %s37%s      %s62%s    %s87%s\n", green, reset, green, reset, green, reset, green, reset);
    printf("/ \\   /                  \n");
    printf("%s6%s %s18%s %s31%s\n", green, reset, green, reset, green, reset);
    printf("\t\t\t\t\t\t\t 6->18->31->62->87->12->37->25->");
}

void leaf_LR_print9()
{
    const char *green = "\033[0;32m";
    const char *reset = "\033[0m";

    printf("          50\n");
    printf("        /    \\\n");
    printf("      /        \\\n");
    printf("    /            \\\n");
    printf("   %s25%s            %s75%s\n", green, reset, green, reset);
    printf("  /  \\          /  \\\n");
    printf(" /    \\        /    \\\n");
    printf("%s12%s    %s37%s      %s62%s    %s87%s\n", green, reset, green, reset, green, reset, green, reset);
    printf("/ \\   /                  \n");
    printf("%s6%s %s18%s %s31%s\n", green, reset, green, reset, green, reset);
    printf("\t\t\t\t\t\t\t 6->18->31->62->87->12->37->25->75->");
}

void leaf_LR_print10()
{
    const char *green = "\033[0;32m";
    const char *reset = "\033[0m";

    printf("          %s50%s\n", green, reset);
    printf("        /    \\\n");
    printf("      /        \\\n");
    printf("    /            \\\n");
    printf("   %s25%s            %s75%s\n", green, reset, green, reset);
    printf("  /  \\          /  \\\n");
    printf(" /    \\        /    \\\n");
    printf("%s12%s    %s37%s      %s62%s    %s87%s\n", green, reset, green, reset, green, reset, green, reset);
    printf("/ \\   /                  \n");
    printf("%s6%s %s18%s %s31%s\n", green, reset, green, reset, green, reset);
    printf("\t\t\t\t\t\t\t 6->18->31->62->87->12->37->25->75->50->end");
}

//===========================================================branch_LR_print===============================================================
void branch_LR_print1()
{
    const char *green = "\033[0;32m";
    const char *reset = "\033[0m";

    printf("          50\n");
    printf("        /    \\\n");
    printf("      /        \\\n");
    printf("    /            \\\n");
    printf("   25            75\n");
    printf("  /  \\          /  \\\n");
    printf(" /    \\        /    \\\n");
    printf("12    37      62    %s87%s\n", green, reset);
    printf("/ \\   /                  \n");
    printf("6 18 31\n");
    printf("\t\t\t\t\t\t\t 87->");
}

void branch_LR_print2()
{
    const char *green = "\033[0;32m";
    const char *reset = "\033[0m";

    printf("          50\n");
    printf("        /    \\\n");
    printf("      /        \\\n");
    printf("    /            \\\n");
    printf("   25            %s75%s\n", green, reset);
    printf("  /  \\          /  \\\n");
    printf(" /    \\        /    \\\n");
    printf("12    37      62    %s87%s\n", green, reset);
    printf("/ \\   /                  \n");
    printf("6 18 31\n");
    printf("\t\t\t\t\t\t\t 87->75->");
}

void branch_LR_print3()
{
    const char *green = "\033[0;32m";
    const char *reset = "\033[0m";

    printf("          %s50%s\n", green, reset);
    printf("        /    \\\n");
    printf("      /        \\\n");
    printf("    /            \\\n");
    printf("   25            %s75%s\n", green, reset);
    printf("  /  \\          /  \\\n");
    printf(" /    \\        /    \\\n");
    printf("12    37      62    %s87%s\n", green, reset);
    printf("/ \\   /                  \n");
    printf("6 18 31\n");
    printf("\t\t\t\t\t\t\t 87->75->50->");
}

void branch_LR_print4()
{
    const char *green = "\033[0;32m";
    const char *reset = "\033[0m";

    printf("          %s50%s\n", green, reset);
    printf("        /    \\\n");
    printf("      /        \\\n");
    printf("    /            \\\n");
    printf("   25            %s75%s\n", green, reset);
    printf("  /  \\          /  \\\n");
    printf(" /    \\        /    \\\n");
    printf("12    37      %s62%s    %s87%s\n", green, reset, green, reset);
    printf("/ \\   /                  \n");
    printf("6 18 31\n");
    printf("\t\t\t\t\t\t\t 87->75->50->62->");
}

void branch_LR_print5()
{
    const char *green = "\033[0;32m";
    const char *reset = "\033[0m";

    printf("          %s50%s\n", green, reset);
    printf("        /    \\\n");
    printf("      /        \\\n");
    printf("    /            \\\n");
    printf("   25            %s75%s\n", green, reset);
    printf("  /  \\          /  \\\n");
    printf(" /    \\        /    \\\n");
    printf("12    37      %s62%s    %s87%s\n", green, reset, green, reset);
    printf("/ \\   /                  \n");
    printf("6 18 %s31%s\n", green, reset);
    printf("\t\t\t\t\t\t\t 87->75->50->62->31->");
}

void branch_LR_print6()
{
    const char *green = "\033[0;32m";
    const char *reset = "\033[0m";

    printf("          %s50%s\n", green, reset);
    printf("        /    \\\n");
    printf("      /        \\\n");
    printf("    /            \\\n");
    printf("   25            %s75%s\n", green, reset);
    printf("  /  \\          /  \\\n");
    printf(" /    \\        /    \\\n");
    printf("12    %s37%s      %s62%s    %s87%s\n", green, reset, green, reset, green, reset);
    printf("/ \\   /                  \n");
    printf("6 18 %s31%s\n", green, reset);
    printf("\t\t\t\t\t\t\t 87->75->50->62->31->37->");
}

void branch_LR_print7()
{
    const char *green = "\033[0;32m";
    const char *reset = "\033[0m";

    printf("          %s50%s\n", green, reset);
    printf("        /    \\\n");
    printf("      /        \\\n");
    printf("    /            \\\n");
    printf("   %s25%s            %s75%s\n", green, reset, green, reset);
    printf("  /  \\          /  \\\n");
    printf(" /    \\        /    \\\n");
    printf("12    %s37%s      %s62%s    %s87%s\n", green, reset, green, reset, green, reset);
    printf("/ \\   /                  \n");
    printf("6 %s18%s %s31%s\n", green, reset, green, reset);
    printf("\t\t\t\t\t\t\t 87->75->50->62->31->37->25->");
}

void branch_LR_print8()
{
    const char *green = "\033[0;32m";
    const char *reset = "\033[0m";

    printf("          %s50%s\n", green, reset);
    printf("        /    \\\n");
    printf("      /        \\\n");
    printf("    /            \\\n");
    printf("   %s25%s            %s75%s\n", green, reset, green, reset);
    printf("  /  \\          /  \\\n");
    printf(" /    \\        /    \\\n");
    printf("12    %s37%s      %s62%s    %s87%s\n", green, reset, green, reset, green, reset);
    printf("/ \\   /                  \n");
    printf("6 %s18%s %s31%s\n", green, reset, green, reset);
    printf("\t\t\t\t\t\t\t 87->75->50->62->31->37->25->18->");
}

void branch_LR_print9()
{
    const char *green = "\033[0;32m";
    const char *reset = "\033[0m";

    printf("          %s50%s\n", green, reset);
    printf("        /    \\\n");
    printf("      /        \\\n");
    printf("    /            \\\n");
    printf("   %s25%s            %s75%s\n", green, reset, green, reset);
    printf("  /  \\          /  \\\n");
    printf(" /    \\        /    \\\n");
    printf("%s12%s    %s37%s      %s62%s    %s87%s\n", green, reset, green, reset, green, reset, green, reset);
    printf("/ \\   /                  \n");
    printf("6 %s18%s %s31%s\n", green, reset, green, reset);
    printf("\t\t\t\t\t\t\t 87->75->50->62->31->37->25->18->12->");
}

void branch_LR_print10()
{
    const char *green = "\033[0;32m";
    const char *reset = "\033[0m";

    printf("          %s50%s\n", green, reset);
    printf("        /    \\\n");
    printf("      /        \\\n");
    printf("    /            \\\n");
    printf("   %s25%s            %s75%s\n", green, reset, green, reset);
    printf("  /  \\          /  \\\n");
    printf(" /    \\        /    \\\n");
    printf("%s12%s    %s37%s      %s62%s    %s87%s\n", green, reset, green, reset, green, reset, green, reset);
    printf("/ \\   /                  \n");
    printf("%s6%s %s18%s %s31%s\n", green, reset, green, reset, green, reset);
    printf("\t\t\t\t\t\t\t 87->75->50->62->31->37->25->18->12->6");
}

void leaf_RL_print()
{
    printf("          50\n");
    printf("        /    \\\n");
    printf("      /        \\\n");
    printf("    /            \\\n");
    printf("   25            75\n");
    printf("  /  \\          /  \\\n");
    printf(" /    \\        /    \\\n");
    printf("12    37      62    87\n");
    printf("/ \\   /                  \n");
    printf("6 18 31                \n");
    printf("\t\t\t\t\t\t\t start");
}
void leaf_RL_print1()
{
    const char *green = "\033[0;32m";
    const char *reset = "\033[0m";

    printf("          50\n");
    printf("        /    \\\n");
    printf("      /        \\\n");
    printf("    /            \\\n");
    printf("   25            75\n");
    printf("  /  \\          /  \\\n");
    printf(" /    \\        /    \\\n");
    printf("12    37      62    %s87%s\n", green, reset);
    printf("/ \\   /                  \n");
    printf("6 18 31\n");
    printf("\t\t\t\t\t\t\t 87->");
}

void leaf_RL_print2()
{
    const char *green = "\033[0;32m";
    const char *reset = "\033[0m";

    printf("          50\n");
    printf("        /    \\\n");
    printf("      /        \\\n");
    printf("    /            \\\n");
    printf("   25            75\n");
    printf("  /  \\          /  \\\n");
    printf(" /    \\        /    \\\n");
    printf("12    37      %s62%s    %s87%s\n", green, reset, green, reset);
    printf("/ \\   /                  \n");
    printf("6 18 31\n");
    printf("\t\t\t\t\t\t\t 87->62->");
}

void leaf_RL_print3()
{
    const char *green = "\033[0;32m";
    const char *reset = "\033[0m";

    printf("          50\n");
    printf("        /    \\\n");
    printf("      /        \\\n");
    printf("    /            \\\n");
    printf("   25            75\n");
    printf("  /  \\          /  \\\n");
    printf(" /    \\        /    \\\n");
    printf("12    37      %s62%s    %s87%s\n", green, reset, green, reset);
    printf("/ \\   /                  \n");
    printf("6 18 %s31%s\n", green, reset);
    printf("\t\t\t\t\t\t\t 87->62->31->");
}

void leaf_RL_print4()
{
    const char *green = "\033[0;32m";
    const char *reset = "\033[0m";

    printf("          50\n");
    printf("        /    \\\n");
    printf("      /        \\\n");
    printf("    /            \\\n");
    printf("   25            75\n");
    printf("  /  \\          /  \\\n");
    printf(" /    \\        /    \\\n");
    printf("12    37      %s62%s    %s87%s\n", green, reset, green, reset);
    printf("/ \\   /                  \n");
    printf("6 %s18%s %s31%s\n", green, reset, green, reset);
    printf("\t\t\t\t\t\t\t 87->62->31->18->");
}

void leaf_RL_print5()
{
    const char *green = "\033[0;32m";
    const char *reset = "\033[0m";

    printf("          50\n");
    printf("        /    \\\n");
    printf("      /        \\\n");
    printf("    /            \\\n");
    printf("   25            75\n");
    printf("  /  \\          /  \\\n");
    printf(" /    \\        /    \\\n");
    printf("12    37      %s62%s    %s87%s\n", green, reset, green, reset);
    printf("/ \\   /                  \n");
    printf("%s6%s %s18%s %s31%s\n", green, reset, green, reset, green, reset);
    printf("\t\t\t\t\t\t\t 87->62->31->18->6->");
}

void leaf_RL_print6()
{
    const char *green = "\033[0;32m";
    const char *reset = "\033[0m";

    printf("          50\n");
    printf("        /    \\\n");
    printf("      /        \\\n");
    printf("    /            \\\n");
    printf("   25            %s75%s\n", green, reset);
    printf("  /  \\          /  \\\n");
    printf(" /    \\        /    \\\n");
    printf("12    37      %s62%s    %s87%s\n", green, reset, green, reset);
    printf("/ \\   /                  \n");
    printf("%s6%s %s18%s %s31%s\n", green, reset, green, reset, green, reset);
    printf("\t\t\t\t\t\t\t 87->62->31->18->6->75->");
}

void leaf_RL_print7()
{
    const char *green = "\033[0;32m";
    const char *reset = "\033[0m";

    printf("          50\n");
    printf("        /    \\\n");
    printf("      /        \\\n");
    printf("    /            \\\n");
    printf("   25            %s75%s\n", green, reset);
    printf("  /  \\          /  \\\n");
    printf(" /    \\        /    \\\n");
    printf("12    %s37%s      %s62%s    %s87%s\n", green, reset, green, reset, green, reset);
    printf("/ \\   /                  \n");
    printf("%s6%s %s18%s %s31%s\n", green, reset, green, reset, green, reset);
    printf("\t\t\t\t\t\t\t 87->62->31->18->6->75->37->");
}

void leaf_RL_print8()
{
    const char *green = "\033[0;32m";
    const char *reset = "\033[0m";

    printf("          50\n");
    printf("        /    \\\n");
    printf("      /        \\\n");
    printf("    /            \\\n");
    printf("   25            %s75%s\n", green, reset);
    printf("  /  \\          /  \\\n");
    printf(" /    \\        /    \\\n");
    printf("%s12%s    %s37%s      %s62%s    %s87%s\n", green, reset, green, reset, green, reset, green, reset);
    printf("/ \\   /                  \n");
    printf("%s6%s %s18%s %s31%s\n", green, reset, green, reset, green, reset);
    printf("\t\t\t\t\t\t\t 87->62->31->18->6->75->37->12->");
}

void leaf_RL_print9()
{
    const char *green = "\033[0;32m";
    const char *reset = "\033[0m";

    printf("          50\n");
    printf("        /    \\\n");
    printf("      /        \\\n");
    printf("    /            \\\n");
    printf("   %s25%s            %s75%s\n", green, reset, green, reset);
    printf("  /  \\          /  \\\n");
    printf(" /    \\        /    \\\n");
    printf("%s12%s    %s37%s      %s62%s    %s87%s\n", green, reset, green, reset, green, reset, green, reset);
    printf("/ \\   /                  \n");
    printf("%s6%s %s18%s %s31%s\n", green, reset, green, reset, green, reset);
    printf("\t\t\t\t\t\t\t 87->62->31->18->6->75->37->12->25->");
}

void leaf_RL_print10()
{
    const char *green = "\033[0;32m";
    const char *reset = "\033[0m";

    printf("          %s50%s\n", green, reset);
    printf("        /    \\\n");
    printf("      /        \\\n");
    printf("    /            \\\n");
    printf("   %s25%s            %s75%s\n", green, reset, green, reset);
    printf("  /  \\          /  \\\n");
    printf(" /    \\        /    \\\n");
    printf("%s12%s    %s37%s      %s62%s    %s87%s\n", green, reset, green, reset, green, reset, green, reset);
    printf("/ \\   /                  \n");
    printf("%s6%s %s18%s %s31%s\n", green, reset, green, reset, green, reset);
    printf("\t\t\t\t\t\t\t 87->62->31->18->6->75->37->12->25->50->end");
}
//===================================================simulation of traversals==========================================================================
void crt_BST_check_trvrsl()
{
    Pointeur_ATib R = NULL;
    Pointeur_Li H = NULL;
    Pointeur_Li T = NULL;
    int I;
    bool A;

    I = 1;
    while (I < 11)
    {
        Cree_arb(&R);
        A = Check_bst(&R);
        if (A == True)
        {
            printf("\n %d", I);
            printf("\n %s", "the tree is a bst with 100 nodes");
        }
        else
        {
            printf(" %d", I);
            printf("\n %s", "the tree number isn''t a bst");
        };
        /*=======================================*/
        Bb_lr(&R, &T);
        Check_branch_lr(&R, &H);
        A = Check_traversal(&T, &H);
        if (A == True)
        {
            printf("\n %s", "traversal one branch by branch L --> R is correct");
        }
        else
        {
            printf("\n %s", "traversal one branch by branch L --> R is false");
        };
        T = NULL;
        H = NULL;
        /*=======================================*/
        Bb_rl(&R, &T);
        Check_branch_rl(&R, &H);
        A = Check_traversal(&T, &H);
        if (A == True)
        {
            printf("\n %s", "traversal one branch by branch R --> L is correct");
        }
        else
        {
            printf("\n %s", "traversal one branch by branch R --> L is false");
        };
        T = NULL;
        H = NULL;
        /*=======================================*/
        Ll_lr(&R, &T);
        Check_ll_lr(&R, &H);
        A = Check_traversal(&T, &H);
        if (A == True)
        {
            printf("\n %s", "traversal two leaf by leaf L --> R is correct");
        }
        else
        {
            printf("\n %s", "traversal two leaf by leaf L --> R is false");
        };
        T = NULL;
        H = NULL;
        /*=======================================*/
        Ll_lr(&R, &T);
        Check_ll_lr(&R, &H);
        A = Check_traversal(&T, &H);
        if (A == True)
        {
            printf("\n %s", "traversal two leaf by leaf R --> L is correct");
        }
        else
        {
            printf("\n %s", "traversal two leaf by leaf R --> L  is false");
        };
        T = NULL;
        H = NULL;
        /*=======================================*/
        R = NULL;
        I = I + 1;
        printf("\n %s", "==========================================");
    };
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    page_acceuil();
    page_chargement();
    welcome();

    int choice;
    int choix;
    Pointeur_Li lists = NULL;
    Pointeur_Li checkli = NULL;
    int sure;
    bool corr;

    do
    {
        menu();
        printf("enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            crt_BST_check_trvrsl();

            getchar();
            printf("press any key to return...");
            getchar();
            break;
        case 2:
            system("cls");
            menu_traversels();
            printf("choose one traversal:  ");
            printf("  if you want to exit write 5: ");

            scanf("%d", &choix);
            switch (choix)
            {
            case 1:
                system("cls");
                Cree_arb(&R);
                printf("BB_LR: ");
                Bb_lr(&R, &lists);
                Printlist(&lists);
                printf("\n");
                printf("check: ");
                Check_branch_lr(&R, &checkli);
                Printlist(&checkli);
                corr = Check_traversal(&lists, &checkli);
                if (corr == True)
                {
                    printf("\n %s", "traversal one branch by branch L --> R is correct");
                }
                else
                {
                    printf("\n %s", "traversal one branch by branch L --> R is false");
                }
                getchar();
                printf("\n");
                printf("press any key to return...");
                getchar();
                break;
            case 2:
                system("cls");
                Cree_arb(&R);
                printf("BB_RL: ");
                Bb_rl(&R, &lists);
                Printlist(&lists);
                printf("\n");
                printf("check: ");
                Check_branch_rl(&R, &checkli);
                Printlist(&checkli);
                corr = Check_traversal(&lists, &checkli);
                if (corr == True)
                {
                    printf("\n %s", "traversal one branch by branch R --> L is correct");
                }
                else
                {
                    printf("\n %s", "traversal one branch by branch R --> L is false");
                }
                getchar();
                printf("\n");
                printf("press any key to return...");
                getchar();

                break;
            case 3:
                system("cls");
                Cree_arb(&R);
                printf("LL_LR: ");
                Ll_lr(&R, &lists);
                Printlist(&lists);
                printf("\n");
                printf("check: ");
                Check_ll_lr(&R, &checkli);
                Printlist(&checkli);
                corr = Check_traversal(&lists, &checkli);
                if (corr == True)
                {
                    printf("\n %s", "traversal two leaf by leaf L --> R is correct");
                }
                else
                {
                    printf("\n %s", "traversal two leaf by leaf L --> R is false");
                };
                getchar();
                printf("\n");
                printf("press any key to return...");
                getchar();
                break;

            case 4:
                system("cls");
                Cree_arb(&R);
                printf("LL_RL: ");
                Ll_rl(&R, &lists);
                Printlist(&lists);
                printf("\n");
                printf("check: ");
                Check_ll_rl(&R, &checkli);
                Printlist(&checkli);
                corr = Check_traversal(&lists, &checkli);
                if (corr == True)
                {
                    printf("\n %s", "traversal two leaf by leaf R --> L is correct");
                }
                else
                {
                    printf("\n %s", "traversal two leaf by leaf R --> L  is false");
                };
                getchar();
                printf("\n");
                printf("press any key to return...");
                getchar();
                break;
            case 5:
                // to exit from the programme
                printf("\033[0;33m"); // Set text color to yellow
                printf("Exiting...\n");
                printf("\033[0m"); // Reset text color to default

                break;
            default:
                break;
            }

            break;
        case 3:
            system("cls");
            testprint();
            usleep(500000); // 500 milliseconds
            system("cls");
            testprint1();
            usleep(500000);
            system("cls");
            testprint2();
            usleep(500000);
            system("cls");
            testprint3();
            usleep(500000);
            system("cls");
            testprint4();
            usleep(500000);
            system("cls");
            testprint5();
            usleep(500000);
            system("cls");
            testprint6();
            usleep(500000);
            system("cls");
            testprint7();
            usleep(500000);
            system("cls");
            testprint8();
            usleep(500000);
            system("cls");
            testprint9();
            usleep(500000);
            system("cls");
            testprint10();
            usleep(500000);
             welcome();
            printf("   =>this is BB_LR");
            getchar();
            printf("\n");
            printf("press any key to return...");
            getchar();
            break;
        case 4:
        system("cls");
            branch_LR_print1();
            usleep(500000);
            system("cls");

            branch_LR_print2();
            usleep(500000);
            system("cls");

            branch_LR_print3();
            usleep(500000);
            system("cls");

            branch_LR_print4();
            usleep(500000);
            system("cls");

            branch_LR_print5();
            usleep(500000);
            system("cls");

            branch_LR_print6();
            usleep(500000);
            system("cls");

            branch_LR_print7();
            usleep(500000);
            system("cls");

            branch_LR_print8();
            usleep(500000);
            system("cls");

            branch_LR_print9();
            usleep(500000);
            system("cls");

            branch_LR_print10();
            usleep(500000);
             welcome();
            printf("  => this is BB_RL ");
            getchar();
            printf("\n");
            printf("press any key to return...");
            getchar();
            break;
        case 5:
             system("cls");
            testprint();
            usleep(500000);
            system("cls");

            leaf_LR_print1();
            usleep(500000);
            system("cls");

            leaf_LR_print2();
            usleep(500000);
            system("cls");

            leaf_LR_print3();
            usleep(500000);
            system("cls");

            leaf_LR_print4();
            usleep(500000);
            system("cls");

            leaf_LR_print5();
            usleep(500000);
            system("cls");

            leaf_LR_print6();
            usleep(500000);
            system("cls");

            leaf_LR_print7();
            usleep(500000);
            system("cls");

            leaf_LR_print8();
            usleep(500000);
            system("cls");

            leaf_LR_print9();
            usleep(500000);
            system("cls");

            leaf_LR_print10();
            usleep(500000);
             welcome();
             printf("\n");
             printf("this is LL_LR");
             getchar();
            printf("\n");
            printf("press any key to return...");
            getchar();
            break;
        case 6:
        system("cls");
            printf("\n");
            system("cls");
            leaf_RL_print();
            usleep(500000); // 500 milliseconds
            system("cls");
            leaf_RL_print1();
            usleep(500000);
            system("cls");
            leaf_RL_print2();
            usleep(500000);
            system("cls");
            leaf_RL_print3();
            usleep(500000);
            system("cls");
            leaf_RL_print4();
            usleep(500000);
            system("cls");
            leaf_RL_print5();
            usleep(500000);
            system("cls");
            leaf_RL_print6();
            usleep(500000);
            system("cls");
            leaf_RL_print7();
            usleep(500000);
            system("cls");
            leaf_RL_print8();
            usleep(500000);
            system("cls");
            leaf_RL_print9();
            usleep(500000);
            system("cls");
            leaf_RL_print10();
            usleep(500000);
            printf("\n");
             welcome();
             printf("\n");
             printf("this is LL_RL");
             getchar();
            printf("\n");
            printf("press any key to return...");
            getchar();
            break;
        case 7:
        printf("are you sure?...");
        printf(": 1/yes \n 0/no: ");
        scanf("%d", &sure);
        if (sure==1){
            printf("thank you for visiting");
            printf("\033[0;33m"); // Set text color to yellow
            printf("Exiting...\n");
            printf("\033[0m"); // Reset text color to default
        }else{
            printf("ok!");
        }
        default:
            printf("Invalid choice. n");
        }
    } while (sure != 1 );

    system("PAUSE");
    return 0;
}






