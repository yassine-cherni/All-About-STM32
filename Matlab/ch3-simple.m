clc;clear all;close all;
Xmin = -5;
Xmax = 5;
n = 1000;
dx = (Xmax - Xmin) / (n - 1);
% x = zeros(1, n);
for i = 1:n
    x(i) = Xmin + (i - 1) * dx;
end

A = zeros(n, n);
G = zeros(n, 1);
F = zeros(n, 1);

A(1, 1) = -1;
A(1, 2) = 1;
G(1,1) = 40 * dx;

A(n, n) = 1;
G(n,1) = 80;

a = (1 / dx^2) + (2 / dx);
b = 8 -(2 / dx^2);
c = (1 / dx^2) - (2 / dx);

for i = 2: n - 1
    A(i, i - 1) = a;
    A(i, i) = b;
    A(i, i + 1) = c;
    G(i,1) = exp(2 * x(i));
end

F = A \ G;

plot(x, F, 'b-');
