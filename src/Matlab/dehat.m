function result = dehat(A)
skewA=(A-A.')/2;
result=[skewA(3,2);-skewA(3,1);skewA(2,1)];
end