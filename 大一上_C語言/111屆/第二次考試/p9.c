// 程式設計一 !! 第二次上機考試 !! 第 9 題 (3分)
//
//  計算並輸出 2 到 50000000 之間所有質數的總數，程式所需要的總時間必須小於規定的秒數 
//        debug 模式必須小於 7.5 秒，release 模式必須小於 5 秒
// 
//  提示：
//     運用 n = p1^n1 * p2^n2 *...* pk^nk，這個公式所表達的含意作為判斷質數的依據
//     其中 p1 到 pk 為質數，n1 到 nk 為自然數，
//     亦即任何的自然數都能寫成一群相異質數的乘積
// 
// 參考輸出
//
// 共有 3001134 個質數，費時 7.454000
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define p
#ifdef p9

int main(void)
{
	double t_start, t_end;

	t_start = clock();
	// -----------------------------------------------------------------
	// 質數的判斷與計算寫在這個範圍內






	// -----------------------------------------------------------------
	t_end = clock();
	printf("共有 %4d 個質數，費時 %f\n",  ,(t_end-t_start)/ CLOCKS_PER_SEC);
	system("pause"); return 0;
}

#endif
