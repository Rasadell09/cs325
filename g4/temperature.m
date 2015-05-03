%Team members: Yunfan Li, Haichao Zhang, Jingyuan Xu
clear;
t = 'Guangzhou';
M = csvread(strcat(t,'.csv'));
si = size(M);
dstr = int2str(M(1,1));
oriD = datenum(datevec(dstr,'yyyymmdd'));
if ~or(M(1,3) == -9999, M(1,2) == -9999)
    d(1,2) = 0;
    tmax = M(1,2)/10;
    tmin = M(1,3)/10;
    d(1,1) = (tmax+tmin)/2;
    in = 2;
else
    in = 1;
end
for i = 2:1:si(1,1)
    if or(M(i,3) == -9999, M(i,2) == -9999)
        continue;
    end
    dstr = int2str(M(i,1));
    nowD = datenum(datevec(dstr,'yyyymmdd'));
    d(in,2) = nowD - oriD;
    tmax = M(i,2)/10;
    tmin = M(i,3)/10;
    d(in,1) = (tmax+tmin)/2;
    in = in + 1;
end
si = size(d);
f = [1;0;0;0;0;0;0];
b = zeros(si(1,1), 1);
A = zeros(si(1,1), 7);
for i=1:1:si(1,1)
    b(2*i-1, 1) = d(i,1);
    b(2*i, 1) = -d(i,1);
    A(2*i-1,:) = [-1, 1, d(i,2), cos((2*pi*d(i,2))/365.25), sin((2*pi*d(i,2))/365.25),...
        cos((2*pi*d(i,2))/(365.25*10.7)), sin((2*pi*d(i,2))/(365.25*10.7))];
    A(2*i,:) = [-1, -1, -d(i,2), -cos((2*pi*d(i,2))/365.25), -sin((2*pi*d(i,2))/365.25),...
        -cos((2*pi*d(i,2))/(365.25*10.7)), -sin((2*pi*d(i,2))/(365.25*10.7))];
end
x = linprog(f,A,b);
figure;
y1 = plot(d(:,2), d(:,1),'.');
hold on;
y2 = plot(d(:,2), x(2,1)+x(3,1)*d(:,2)+x(4,1)*cos((2*pi*d(:,2))/365.25)+...
    x(5,1)*sin((2*d(:,2))/365.25)+x(6,1)*cos((2*pi*d(:,2))/(365.25*10.7))+...
    x(7,1)*sin((2*pi*d(:,2))/(365.25*10.7)));
hold on;
y3 = plot(d(:,2), x(2,1)+x(3,1)*d(:,2), 'LineWidth', 5);
set(gca, 'ylim', [-20 40]);
title(t);
xlabel('Day');
ylabel('Average Temperature');
legend([y1,y2,y3],'Daily Average Temperature', 'Best FitCurve', 'Linear part of Curve');