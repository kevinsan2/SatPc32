function [s, flag] = arduinoDisplay(comPort)

flag = 1;
delete(instrfind);
s = serial(comPort);
set(s,'DataBits', 8 );
set(s,'StopBits', 1 );
set(s,'BaudRate', 9600);
set(s,'Parity', 'none');
fopen(s);
% a = 'b';
% while ( a ~= 'a')
%     a = fread(s, 1, 'uchar');
% end
% if (a == 'a')
%     disp('serial read');
% end
% fprintf(s,'%c','a');
mbox = msgbox('Serial Communication setup.');
uiwait(mbox);