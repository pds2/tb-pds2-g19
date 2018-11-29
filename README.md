# tb-pds2-g19

# UNO

## Início do jogo

No início do jogo você será solicitado a especificar o número de jogadores (pessoas) e bots (jogadores simulados pelo programa) 
separadamente. O total de jogadores mais bots deve estar entre 2 e 10. Logo depois serão pedidos os nomes dos jogadores 
participantes (somente as pessoas, os bots recebem nomes automaticamente).
Serão criados pelo programa o baralho, de onde cartas são compradas, e a pilha, onde cartas são depositadas. A pilha receberá 
a primeira carta que dará início ao jogo, que será impressa na primeira rodada e nunca será uma cata de ação. Também serão 
distribuídas 7 cartas para cada jogador.
No caso de haverem bots o jogador poderá escolher se a mão do bot será ou não impressa na tela a cada jogada.

## A Cada Rodada

A cada rodada será impressa na tela a carta atual, o nome do jogador atual e as suas cartas e o jogador deverá informar se ele
quer jogar nessa rodada ou comprar uma carta e perder a vez. Caso o jogador não tenha cartas jogáveis ele irá automaticamente comprar uma
carta do baralho, se essa carta for jogável, ele pode depositá-la na pilha, senão ele é pulado. Um aviso será impresso na tela dizendo que
“O jogador X não tem cartas jogáveis e teve que comprar uma”. Caso o jogador tenha cartas jogáveis ele será solicitado a escolher uma carta
pelo seu índice de posição para ser jogada. Caso o jogador escolha uma carta inválida ele será solicitado novamente, até que escolha uma
carta válida.

## Regra do Jogo

O objetivo do jogo é acabar com as cartas em sua mão. Quem descartar todas as cartas primeiro vence. Uma carta pode ser 
colocada na pilha se tiver a mesma cor, o mesmo valor da última carta da pilha, ou for uma carta especial.

## Cartas de Ação

###### **Cartas de Ação com Cores**

**PULAR**: Essa carta pula a vez do jogador seguinte, então se os jogadores A, B e C estão jogando (nessa ordem) e o A usa uma 
carta PULAR, o próximo jogador será o C. No caso de haverem apenas dois jogadores, essa carta tem o efeito de voltar a jogada 
para o jogador que a usou, então se A e B estão jogando e A usa a carta PULAR, o próximo jogador será A de novo.
**REVERTER**: Carta que reverte o sentido do jogo. Se os jogadores A, B e C estão jogando nessa ordem e o C usa uma carta REVERTER, o
próximo jogador será o B e a ordem passará a ser C, B, A. No caso de haverem apenas dois jogadores, essa carta tem o efeito de voltar a
jogada para o jogador que a usou, então se A e B estão jogando e A usa a carta REVERTER, o próximo jogador será A de novo.
**COMPRA 2**: Essa carta tem o efeito de fazer o jogador seguinte comprar duas cartas do baralho. Caso o jogador receba uma 
carta COMPRA 2 e tenha outra na sua mão (de qualquer cor), ele pode jogá-la e assim, o jogador seguinte terá que comprar 4
cartas, sendo que o atual será isento do efeito da carta. Se o jogador seguinte também possuir um COMPRA 2 em sua mão, ele
também poderá jogá-lo, fazendo o seu próximo comer 6 cartas e assim por diante. Ou seja, o efeito da carta é cumulativo. O
jogador que sofrer o efeito da carta perde a vez.

###### **Cartas Especiais**

**COMPRA 4**: Essa carta tem o efeito de fazer o jogador seguinte comprar quatro cartas do baralho e de possibilitar ao jogador 
que a usou a escolha da cor da próxima carta a ser jogada. Caso o jogador receba uma carta COMPRA 4 e tenha outra na sua mão, 
ele pode jogá-la e assim, o jogador seguinte terá que comprar 8 cartas, sendo que o atual será isento do efeito da carta. Se o 
jogador seguinte também possuir um COMPRA 4 em sua mão, ele também poderá jogá-lo, fazendo o seu próximo comer 12 cartas e 
assim por diante. Ou seja, o efeito da carta é cumulativo. O jogador que sofrer o efeito da carta perde a vez.
**CORINGA**: Tem o efeito de possibilitar ao jogador que a usar a escolha da cor da próxima carta a ser jogada. Caso o jogador 
seguinte não tenha  a cor escolhida ou uma especial, ele deve comprar uma carta do baralho, se essa também não for da cor 
escolhida ou especial, ele perde a vez, e assim por diante até que um dos jogadores tenha uma carta da cor escolhida ou especial.
