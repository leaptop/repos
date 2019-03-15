//когда пишу х1, х2 и т.д., то имею ввиду конечно коэффициенты в матрице при переменных х1, х2 и т.д.
import java.io.*;
public class mainGauss {  //public class GaussianElimination {
   
    // Gaussian elimination with partial pivoting
    public static double[] lsolve(double[][] A, double[] b) {
        int n = b.length;

        for (int p = 0; p < n; p++) {

            // find pivot row and swap//нохожу индекс строки с наибольшим модулем первого члена
            int max = p;
            for (int i = p + 1; i < n; i++) {
                if (Math.abs(A[i][p]) > Math.abs(A[max][p])) {
                    max = i;//каждый последующий сравнивается с максимальным
                }//при первом проходе основного цикла сравниваются первые элементы(р = 0), i меняется
            }
            double[] temp = A[p]; A[p] = A[max]; A[max] = temp;//меняю строки местами(первую с максимальной)
            double   t    = b[p]; b[p] = b[max]; b[max] = t;//здесь одномерный массив, так что просто числа переставляются
//р - тую в темп(р = 0), нулевой максовую, указатель на максовую теперь указывает на темповую(изначально нулевую)
            // pivot within A and b
            for (int i = p + 1; i < n; i++) {
                double alpha = A[i][p] / A[p][p];//перв прох: alpha = х1(из второй строки)/х1(из первой строки)
                //во втором проходе: alpha = х1(из третьей строки)/х1(из первой строки)
                b[i] -= alpha * b[p];//сначала из х4 второй строки вычитаем alpha*x4(из первой строки)
                for (int j = p; j < n; j++) {//потом х1[вторая] = х1[вторая] - alpha* х1[первая]
                    A[i][j] -= alpha * A[p][j];//и так делаем для каждого столбца вышеуказанных строк
                }//в итоге первый элемент(х1 вторй строки) занулён
            }//в итоге все х1 занулены(кроме первой строки конечно)
        }//р увеличивается. Дальше всё повторяется для х2, начиная со второй строки. Причём строка с мксимальным
        //модулем ведущего элемента также поднимается наверх. Ведущий элемент здесь А[i][p]... короче р-ый столбец

        // back substitution
        double[] x = new double[n];
        for (int i = n - 1; i >= 0; i--) {
            double sum = 0.0;
            for (int j = i + 1; j < n; j++) {
                sum += A[i][j] * x[j];
            }//здесь в общем коэффициенты A[i][j] домножаются на решения(х[j]) и произведения складываются
            x[i] = (b[i] - sum) / A[i][i];//сначала sum = 0, в итоге переменная х3(не коэффициент при х3) = х4/х3
        }// в итоге из х4(константа или свободный член) вычитаются посчитанные числа, кроме неизвестной переменной
        return x;//потом разность делится на коэффициент при неизвестной переменной х
    }



    public static void main(String[] args) {
        int n = 3;
        double[][] A = {
                { 2, -1,  1 },
                { -1, 2, -1 },
                { 3, 1, -2 }
        };
        double[] b = { 1, 0, -3 };
        double[] x = lsolve(A, b);//здесь хранятся ответы


        // распечатка результатов:
        for (int i = 0; i < n; i++) {
            System.out.println(x[i]);
        }

    }

}