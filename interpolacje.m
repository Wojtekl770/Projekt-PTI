function [y2] = interpolacje(y1)
% Interpolacje danych potrzebnych do obliczania norm
% y1 - wektor zapotrzebowania energetycznego dla danej grupy wiekowej, płci
% i wagi dla wskaźnika PAL 1.4, 1.6, 1.75, 2.0, 2.2, 2.4 (wzięte z norm 
% żywienia dla ludności Polski).
% Funkcja inter- i ekstrapoluje liniowo zapotrzebowanie dla wskaźnika PAL 1.2 i 1.8

close all
figure
hold on

% W normach żywienia wartości są podawane dla różnych wartości PAL

if length(y1) == 6
    x=[1.4, 1.6, 1.75, 2.0, 2.2, 2.4];
else 
    x=[1.4, 1.6, 1.75, 2.0, 2.2];
end

% x2 reprezentuje wektor PAL, dla których będziemy interpolować wartości

x2=[1.2, 1.4, 1.6, 1.8, 2.0];

% Rysujemy na jednym wykresie wartości przybliżone i dokładne, by sprawdzić czy metoda jest odpowiednia

plot(x,y1,'-r');
y2=interp1(x,y1, x2, 'linear', 'extrap');
plot(x2,y2,'-g');
legend("Wartości dokładne", "Wartości ekstrapolowane");

end %function
