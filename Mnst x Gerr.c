#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main () {
    int vida_m, vida_c, atq_m, atq_c, stm_c, rec_hp, rec_st;
    int periodo_b = 1;
    int acao, acao_m;
    int vlr_desc = 0;
    int queimando = 0;
    vida_m = 50;
    vida_c = 20;
    atq_m = 4;
    atq_c = 3;
    stm_c = 10;
    rec_hp = 3;
    rec_st = 3;
    srand(time(NULL));
    system ("cls");
    printf("Um monstro aparece! Prepare-se para batalha!\n");
    while (periodo_b == 1) {
        if (queimando == 1) {
            printf("O guerreiro esta queimando! Perdera 1 de vida a cada rodada.\nUse descansar para se curar\n\n");
            vida_c--;
        }
        printf("Monstro %d/50 HP\nGuerreiro %d/20 HP %d ATQ %d ST\nSua vez! Escolha uma acao:\n1- Atacar: Literalmente o que voce esta pensando (-2 Stamina)!\n2- Descansar: Recupera vida, stamina e efeitos negativos\n3- Intimidar: Surpreendentemente, abaixa o ataque do monstro\n4- Determinar: Aumenta o proprio ataque\n", vida_m, vida_c, atq_c, stm_c);
        scanf("%d", &acao);
        switch (acao) {
            case 1:
                if (stm_c >= 2) {
                    printf("Voce ataca o monstro! Causa %d de dano!\n\n", atq_c);
                    vida_m = vida_m - atq_c;
                    stm_c = stm_c - 2;
                    vlr_desc = 0;
                    sleep(1);
                    break;
                }
                else {
                    printf("O guerreiro fadiga...\n");
                    printf("1 ponto de stamina e recuperado\n");
                    stm_c++;
                    break;
                }
            case 2:
                if (vlr_desc == 0) {
                    rec_hp = 3;
                    rec_st = 3;
                    if (queimando == 0) {
                        printf("Voce se recupera um pouco da batalha\nRecuperou %d de vida e %d de stamina e um pouco de vitalidade\n\n", rec_hp, rec_st);
                        vida_c = vida_c + rec_hp;
                        stm_c = stm_c + rec_st;
                        vlr_desc++;
                        sleep(1);
                    }
                    else {
                        rec_st = 2;
                        printf("Voce se recupera um pouco da batalha\nRecupero-se da queimadura e %d de stamina e um pouco de vitalidade\n\n", rec_st);
                        stm_c = stm_c + rec_st;
                        queimando--;
                        vlr_desc++;
                        sleep(1);
                    }
                }
                else if (vlr_desc >= 1 && vlr_desc <= 2) {
                    rec_hp = 3;
                    rec_st = 2;
                    if (queimando == 0) {
                        printf("O guerreiro acua...\nRecuperou %d de vida e %d de stamina\n\n", rec_hp, rec_st);
                        vida_c = vida_c + rec_hp;
                        stm_c = stm_c + rec_st;
                        vlr_desc++;
                        sleep(1);
                    }
                    else {
                        rec_st = 2;
                        printf("O guerreiro acua...\nRecupero-se da queimadura e %d de stamina e um pouco de vitalidade\n\n", rec_st);
                        stm_c = stm_c + rec_st;
                        queimando--;
                        vlr_desc++;
                        sleep(1);
                    }
                }
                else {
                    rec_hp = 0;
                    rec_st = 1;
                    if (queimando == 0) {
                        printf("Parece que o guerreiro e um baiano\nRecuperou %d de stamina, mas perdeu 1 pontos de ataque\n\n", rec_st);
                        atq_c = atq_c - 1;
                        stm_c = stm_c + rec_st;
                        vlr_desc++;
                        sleep(1);
                    }
                     else {
                        rec_st = 0;
                        printf("Parece que o guerreiro e um baiano\nRecuperou-se da queimadura, mas perde 1 de ataque\n\n");
                        queimando--;
                        vlr_desc++;
                        atq_c = atq_c - 1;
                        sleep(1);
                    }
                }
                break;
            case 3:
                if (stm_c <= 1) {
                    printf("Voce mostra voracidade humana contra o monstro!\nAtaque do monstro caiu em 1\n\n");
                    atq_m = atq_m - 1;
                    vlr_desc = 0;
                    stm_c = stm_c - 1;
                    sleep(1);
                    break;
                }
                else {
                    printf("O guerreiro fadiga...\n");
                    printf("1 ponto de stamina e recuperado\n");
                    stm_c++;
                    break;
                }

            case 4:
                if (stm_c >= 1) {
                    if (3 - atq_c <= 1) {
                        printf("O guerreiro se lembra do motivo de lutar\nSeu ataque elevou em 1\n\n");
                        atq_c++;
                        stm_c = stm_c - 1;
                        sleep(1);
                        break;
                    }
                    else {
                        printf("O guerreiro se lembra do motivo de lutar\n");
                        sleep(1);
                        printf("Ele sabe que precisa vencer!\n");
                        sleep(1);
                        printf("O ataque do guerreiro subiu em 2\n");
                        atq_c++;
                        stm_c = stm_c - 1;
                        sleep(1);
                        break;
                    }
                else {
                    printf("O guerreiro fadiga...\n");
                    printf("1 ponto de stamina e recuperado\n");
                    stm_c++;
                    break;
                }
                }
        }
        printf("Cuidado! O monstro vai agir!\n");
        acao_m = rand() % 4;
        sleep(1);
        switch (acao_m) {
            case 0:
            printf("O monstro ataca com toda sua forca!\nCausa %d de dano!\n", atq_m);
            vida_c -= atq_m;
            sleep(2);
            break;
            case 1:
            printf("O monstro se recobra com um ataque leve\nSeu ataque retornou para 4");
            vida_c -= 1;
            atq_m = 4;
            sleep(2);
            break;
            case 2:
            printf("O monstro usa um ataque flamejante!\nO guerreiro fica queimado, mas o ataque do monstro cai em 1\n");
            queimando = 1;
            atq_m--;
                if (atq_m < 1) {
                    atq_m = 1;
                }
            sleep(2);
            break;
            case 3:
            printf("O monstro ruge em furia!\n");
            sleep(1);
            printf("O guerreiro teme!\n");
            sleep(1);
            printf("O ataque do guerreiro caiu em 1\n\n");
            atq_c = atq_c - 1;
            sleep(2);
            break;
        }
        if (vida_c <= 0) {
            periodo_b = 0;
            printf("O guerreiro foi derrotado... Voce perdeu");
        }
        else if (vida_m == 0) {
            periodo_b = 0;
            printf("O guerreiro derrotou o monstro! Voce venceu!");
        }
        else {
            printf("...\n");
        }
    }
return 0;
} 
