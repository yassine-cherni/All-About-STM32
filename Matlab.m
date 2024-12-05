clc;clear all;close all;
L=5*10^-2;
n=500;
T0=80;
TL=20;
linda0=45;
k=2000;
dq=8*10^6;
B(1,1)=T0;
B(n,1)=TL;
A=zeros(n,n);
A(1,1)=1;
A(n,n)=1;
pas=L/(n-1);
for i=1:n
  x(i)=pas*(i-1);
end
for i=2:n-1
B(i,1)=-dq;
A(i,i)=-2*((linda0+x(i)*k)/(x(i)-x(i-1))^2);
A(i,i+1)=(linda0+x(i)*k)/(x(i)-x(i-1))^2 +k/(2*(x(i+1)-x(i-1)));
A(i,i-1)=(linda0+x(i)*k)/(x(i)-x(i-1))^2 -k/(2*(x(i+1)-x(i-1)));
end
T=A\B;
plot(x,T,'g-*');
ylabel("température d'un circuit intégré");
xlabel("n-noeuds");
title("L'évolution de la température dans un circuit intégré de longueur L=5 cm");
