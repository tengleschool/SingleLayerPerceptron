#include <cstdio>
#include <cmath>
using namespace std;

double sigmoid(double x)
{
    return 1 / (1 + exp(-x));
}

double sigmoiddif(double x)
{
    return (1 - x) * x;
}

double
x[4][2] = {
    {0, 0},
    {0, 1},
    {1, 0},
    {1, 1}};

double t[4] = {0, 0, 0, 1};

double w1, w2, bias, rate;
int n;

void input()
{
    puts("0<w1<1");
    scanf("%lf", &w1);
    
    puts("0<w2<1");
    scanf("%lf", &w2);
    
    puts("0<bias<1");
    scanf("%lf", &bias);
    
    puts("0<learning rate<1");
    scanf("%lf", &rate);
    
    puts("epoch");
    scanf("%d", &n);
    
    return;
}

void output()
{
    printf("epoch:%d w1:%.15f w2:%.15f bias:%.15f\n", n, w1, w2, bias);
    for (int i = 0; i < 4; i++) {
        double y = sigmoid(x[i][0] * w1 + x[i][1] * w2 + bias);
        
        printf("input: (%.1f %.1f)\n", x[i][0], x[i][1]);
        printf("output: %.15f\n", y);
        printf("target: %.15f\n\n", t[i]);
    }
    
    return;
}

int main()
{
    input();

    double y, error, adj;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 4; j++) {
            y = sigmoid(x[j][0] * w1 + x[j][1] * w2 + bias);
            
            error = t[j] - y;
            
            adj = error * sigmoiddif(y);
            
            w1 += rate * adj * x[j][0];
            w2 += rate * adj * x[j][1];
            bias += rate * adj;
        }
    }
    
    output();
    
    return 0;
}
