function dir  = rotorDirection( currentValue, lastValue )
%ROTORDIRECTION Summary of this function goes here
%   Detailed explanation goes here
if currentValue < lastValue
    dir = 'd'; % down
elseif currentValue > lastValue
    dir = 'u';
else
    dir = 's';
end
end

