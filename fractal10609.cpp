    #include <bits/stdc++.h>
    using namespace std;
    double eps = 1e-8;
    struct P{
        double x,y;

        bool operator < (const P &p) const{
            if(x+eps < p.x) return true;
            else if (abs(x-p.x)<=eps) return (y < p.y);
            return false;
        }

        bool operator == (const P &p) const{
            return (abs(x-p.x)<=eps) && (abs(y-p.y)<=eps);
        }
    };




    set<P> fractal;

    double minL;

    double x3,y3,x2,y2;

    int sign(P a, P v2)
    {
      if (a.y*v2.x > a.x*v2.y)
      {
        return -1;
      }
      else
      {
        return 1;
      }
    }
    double dist(P a, P b){
        double dist = (a.x-b.x)*(a.x-b.x);
        dist+=(b.y-a.y)*(b.y-a.y);
        return sqrt(dist);
    }

    double norm(P a){
        P z;
        z.x = 0; z.y = 0;
        return dist(a,z);
    }

    P normal(P v){
        P n;
        if(v.x != 0){
            n.x = (v.y/v.x);
            n.y = -1;
        }

        else{
            n.x = 1;
            n.y = 0;
        }

        double norma = norm(n)*sign(v,n);
        n.x/=norma;
        n.y/=norma;
        return n;
    }

    void doFractal(P a, P b){
        double len = dist(a,b);
        if(len < minL) return;
        fractal.insert(a);
        fractal.insert(b);

        P resta;
        resta.x = b.x-a.x;
        resta.y = b.y-a.y;

        P mid;
        mid.x = (b.x+a.x)/2;
        mid.y = (b.y+a.y)/2;

        P c;
        c.x = (mid.x+a.x)/2;
        c.y = (mid.y+a.y)/2;

        P d;
        d.x = (mid.x+b.x)/2;
        d.y = (mid.y+b.y)/2;

        P normalp=normal(resta);

        double hip = len/2;
        double reqsize = sqrt(hip*hip - hip*hip/4);
        normalp.x*=reqsize;
        normalp.y*=reqsize;

        P e;
        e.x = normalp.x+mid.x;
        e.y = normalp.y+mid.y;
        //cout << resta.x << " " << resta.y << " "<< normalp.x << " " << normalp.y << " " << endl;

        doFractal(c,e);
        doFractal(e,d);
    }

    int main(){
        scanf("%lf %lf %lf %lf %lf",&x3,&y3,&x2,&y2,&minL);
        int cas = 1;
        while(minL >= 1){
            fractal.clear();
            P a;
            a.x = x3;
            a.y = y3;

            P b;
            b.x = x2;
            b.y = y2;

            doFractal(a,b);

            cout << "Case "<<cas<<":"<<endl;
            ++cas;
            cout << fractal.size() << endl;
            for(set<P>::iterator it = fractal.begin(); it != fractal.end(); ++it){
                printf("%4.6f ",it->x);
                printf("%4.6f\n",it->y);
            }
            scanf("%lf %lf %lf %lf %lf",&x3,&y3,&x2,&y2,&minL);
        }
    }
