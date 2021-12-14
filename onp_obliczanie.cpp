int Oblicz(string onp) {
    stack <int> stos;;
    for(int i=0; i<onp.size(); i++)
        if(onp[i]>='0'&&onp[i]<='9')
            stos.push(onp[i]-48);
        else {
            int arg2=stos.top(); stos.pop();
            int arg1=stos.top(); stos.pop();
            switch(onp[i]) {
                case '+':
                    stos.push(arg1+arg2);
                    break;
                case '-':
                    stos.push(arg1-arg2);
                    break;
                case '*':
                    stos.push(arg1*arg2);
                    break;
                case '/':
                    stos.push(arg1/arg2);
                    break;
                
            }
        }
    int wynik=stos.top();
    stos.pop();
    return wynik;
}
