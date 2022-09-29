/*
-  ����:��ټ�
-  �Ͻ�:2022�� 9�� 29��
-  ����:Basic RPG game
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int player_hp = 100;
	int player_attack = 10;
	int player_defence = 8;

	int monster_hp = 800;
	int monster_attack = 10;
	int monster_defence = 8;

	srand(time(NULL));
	// while�� ���ǽ� ��ȣ�ȿ� ������ ���ΰ� ������ 1�� �� 0�� ����
	while (1) {
		printf("Player stats ==========================\n");
		printf("- HP: %d\n", player_hp);
		printf("- ATT: %d\n", player_attack);
		printf("- DEF: % d\n", player_defence);

		printf("monster stats ==========================\n");
		printf("- HP: %d\n", monster_hp);
		printf("- ATT: %d\n", monster_attack);
		printf("- DEF: % d\n", monster_defence);


		printf("Menu ==========================\n");
		printf("1. Attack\n");
		printf("2. Defense.\n");
		printf("3. Run.\n");

		int choice;
		scanf("%d", &choice);

		if (choice == 1) {
			int damage = player_attack - monster_defence;
			int is_critical = rand() % 2; //True �ƴϸ� False�� ������ ���� ����

			if (is_critical) damage *= 2;

			printf("Hit the monster with damage %d.\n", damage);
			monster_hp -= damage;
		}
		else if (choice == 2) {
			int damage = monster_attack - player_attack;
			int is_critical = rand() % 2;

			if (is_critical) damage *= 2;

			printf("Got damage %d from the monster.\n", damage);
			player_hp -= damage;
		}
		else if (choice == 3) {
			printf("Bye bye!\n");
			break;
		}
		else {
			printf("Wrong input\n");
			continue; // ���� ������ �ִ� ������ ������ �ö󰣴�.
		}

		if (player_hp <= 0) {
			printf("You loose.\n");
			break;
		}
		else if (monster_hp <= 0) {
			printf("You won.\n");
			break;
		}

	}

	return 0;