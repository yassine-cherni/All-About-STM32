clc; clear all;
% Paramètres
xmin = -5;
xmax = 5;
N = 3000;
M = (xmax - xmin) / (N - 1);

% Initialisation des matrices et vecteurs
A = zeros(N, N);
G = zeros(N, 1);

% Conditions initiales
A(1, 1) = -1;
A(1, 2) = 1;
A(N, N) = 1;
G(1) = 40 * M;
G(N) = 80;

A0(1, 1) = cos(-10) - sin(-10);
A0(1, 2) = cos(-10) + sin(-10);
B0(1, 1) = -0.25 + 20 * exp(10);
A0(2, 1) = cos(10);
A0(2, 2) = sin(10);
B0(2, 1) = -0.25 + 80 * exp(-10);

X0 = A0 \ B0;
C1 = X0(1, 1);
C2 = X0(2, 1);

% Construction du vecteur X
for i = 1:N
    x(i) = xmin + M * (i - 1);
    fth(i) = exp(2 * x(i)) * (C1 * cos(2 * x(i)) + C2 * sin(2 * x(i)) + 0.25);
end

p = 1 / (M^2) + 2 / M;
y = 0-2 / (M^2);
w = 1 / (M^2) - 2 / M;

% Construction des coefficients de la matrice A et du vecteur G
for i = 2:(N - 1)
    A(i, i - 1) = p;
    A(i, i) = y;
    A(i, i + 1) = w;
    G(i) = exp(2 * x(i));
end

% Résolution du système
F = A \ G;

% Tracé de la dernière solution G
figure;
plot(x, F, 'LineWidth', 1.5, 'Color', 'b');
hold on;
plot(x, fth, 'LineWidth', 1.5, 'Color', 'r');
hold off;

xlabel('r');
ylabel('u(r)');
title('Solution U(r) pour k = dernière valeur');
grid on;
