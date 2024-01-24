#include <stdio.h>
#include <stdlib.h>

/*
 * BMIの計算
 * 参考サイト：BMIと肥満度を計算してみよう
 *     　 URL：http://www.uemura-clinic.com/dmlecture/bmi.htm
 * 身長(m), 体重(kg)から数値を計算
 */

void getData(void);/*関数getDataの宣言
					            戻り値（返り値）もナシ、引数もナシ*/
double bmi(void);/*関数bmiの宣言
				  戻り値（返り値）は実数、引数はナシ*/
void judge(void);/*関数judgeの宣言
					            戻り値（返り値）もナシ、引数もナシ*/

// グローバル変数 main関数でもgetDataでもbmiでもjudgeでも共通して使える
double h, w;

int main(void)
{
	getData();// ←getData関数を呼び出す 1
	judge();// ←judge関数を呼び出す   2

	return (0);
}

/*関数getDataの定義*/
void getData(void){
	char a[10],b[10];
	printf("身長(m), 体重(kg)からBMIを計算\n");
	fgets(a,9,stdin);
    fgets(b,9,stdin);
	h = atof(a);
	w = atof(b);
	if (h > 140){
		printf("\n本当に身長%7.2f(m)ですか？\n%7.2f(cm)として計算しておきます。\n\n",h,h);
		h = h / 100;//m から cm に変換
	}
}

/*関数bmiの定義*/
double bmi(void){
	//↓ローカル変数ansの宣言
	double ans;
	if (w == 0.0 || h == 0.0){
		ans = 0;
	}
	else if (w < 0 || h < 0){
		ans = -1;
	}
	else{
		//値をグローバル変数wとhから計算
		ans = w/(h*h);
	}
	return ans;
}

/*関数judgeの定義*/
void judge(void){
	double b;//getData関数のローカル変数bとは別物
	b=bmi();        // ←bmi関数を呼び出す   3
	if (b < 0){
		printf("h:%6.2f,w:%6.2f 反重力？\n",h,w);
	}
	else if (b == 0){
		printf("h:%6.2f,w:%6.2f 無重力？\n",h,w);
	}
	else if (b < 18.5){
		printf("BMI:%5.2f 低体重\n",b);
	}
	else if (b < 25){
		printf("BMI:%5.2f 普通体重\n",b);
	}
	else{
		printf("BMI:%5.2f 肥満\n",b);
	}
}
