time=zeros(10,10,4);
%插入，堆，快速，归并
time(1,:,:)=[
    1.387 0.008 0.007 0.008 
1.379 0.009 0.007 0.008 
1.356 0.009 0.006 0.008 
1.378 0.008 0.006 0.008 
1.375 0.008 0.007 0.008 
1.387 0.009 0.007 0.007 
1.376 0.009 0.006 0.008 
1.356 0.009 0.006 0.009 
1.382 0.008 0.006 0.008 
1.374 0.008 0.007 0.008  ];
time(2,:,:)=[
    5.44 0.018 0.014 0.018 
5.425 0.017 0.013 0.018 
5.446 0.017 0.014 0.017 
5.43 0.017 0.014 0.018 
5.437 0.017 0.014 0.017 
5.48 0.018 0.014 0.018 
5.42 0.018 0.013 0.018 
5.441 0.017 0.014 0.017 
5.425 0.016 0.014 0.018 
5.447 0.017 0.014 0.017  ];
time(3,:,:)=[
    14.476 0.037 0.028 0.037 
15.238 0.033 0.026 0.034 
15.276 0.034 0.025 0.035 
15.3 0.034 0.025 0.03 
15.44 0.06 0.047 0.056 
14.47 0.037 0.028 0.037 
15.238 0.033 0.026 0.034 
15.276 0.028 0.025 0.035 
15.38 0.031 0.025 0.03 
15.44 0.04 0.047 0.056  ];
time(4,:,:)=[
    27.805 0.043 0.038 0.046 
27.573 0.05 0.039 0.045 
27.792 0.048 0.034 0.045 
27.067 0.049 0.039 0.05 
27.233 0.041 0.037 0.058 
27.705 0.043 0.038 0.046 
27.584 0.05 0.039 0.045 
27.472 0.048 0.034 0.045 
27.12 0.049 0.039 0.05 
27.237 0.041 0.037 0.058  ];
time(5,:,:)=[
    42.788 0.06 0.042 0.054 
47.463 0.055 0.045 0.057 
43.053 0.052 0.044 0.053 
43.091 0.061 0.052 0.064 
43.159 0.057 0.051 0.057 
42.796 0.06 0.042 0.054 
45.325 0.055 0.045 0.057 
48.03 0.052 0.044 0.053 
49.857 0.061 0.052 0.064 
43.13 0.057 0.051 0.057  ];
time(6,:,:)=[
    62.029 0.067 0.061 0.063 
61.931 0.064 0.05 0.068 
64.399 0.07 0.065 0.079 
62.4 0.074 0.059 0.072 
62.581 0.083 0.057 0.065 
62.029 0.067 0.061 0.063 
61.931 0.064 0.05 0.068 
60.399 0.07 0.065 0.079 
62.4 0.074 0.059 0.072 
62.581 0.073 0.057 0.065  ];
time(7,:,:)=[
    84.977 0.094 0.066 0.078 
84.869 0.081 0.073 0.082 
84.233 0.101 0.086 0.076 
84.57 0.077 0.091 0.087 
86.663 0.085 0.07 0.076 
84.977 0.094 0.066 0.078 
84.869 0.081 0.073 0.082 
84.233 0.079 0.086 0.076 
84.57 0.077 0.091 0.087 
86.663 0.085 0.07 0.076  ];
time(8,:,:)=[
    110.861 0.097 0.078 0.1 
110.867 0.1 0.088 0.087 
112.428 0.092 0.086 0.084 
108.877 0.108 0.087 0.087 
110.368 0.097 0.075 0.091 
110.861 0.097 0.078 0.1 
110.867 0.1 0.088 0.087 
109.32 0.092 0.086 0.084 
108.877 0.108 0.087 0.087 
110.368 0.097 0.075 0.091  ];
time(9,:,:)=[
    141.539 0.103 0.088 0.108 
138.074 0.105 0.095 0.095 
138.061 0.104 0.098 0.105 
144.704 0.12 0.1 0.094 
137.429 0.104 0.1 0.101 
141.539 0.103 0.088 0.108 
138.074 0.105 0.095 0.095 
138.061 0.104 0.098 0.105 
136.704 0.12 0.1 0.094 
137.429 0.104 0.1 0.101  ];
time(10,:,:)=[
    172.857 0.124 0.106 0.101 
173.404 0.115 0.11 0.118 
175.714 0.117 0.12 0.14 
174.486 0.123 0.102 0.114 
173.278 0.127 0.114 0.121 
172.857 0.124 0.106 0.101 
173.404 0.115 0.11 0.118 
175.714 0.117 0.12 0.14 
174.486 0.123 0.102 0.114 
173.278 0.127 0.114 0.121 
 ];
time_ave=zeros(10,4);
time_var=zeros(10,4);
for i=1:10
    for j=1:4
        time_ave(i,j)=mean(time(i,:,j));
        time_var(i,j)=var(time(i,:,j));
    end
end
time_std=time_var.^(0.5);
index=ones(10,1);
for i=1:10
    index(i)=i*5;
end
%% 子图
subplot(2,2,1);
errorbar(index,time_ave(:,1),time_std(:,1),'ro-');
hold on
errorbar(index,time_ave(:,2),time_std(:,2),'gx-');
hold on
errorbar(index,time_ave(:,3),time_std(:,3),'b.-');
hold on
errorbar(index,time_ave(:,4),time_std(:,4),'k*-');
xlabel('n=x*1e4');ylabel('second');
title('均值比较');
legend('Insert','Heap','Quick','Merge','location','northwest');

subplot(2,2,2);
errorbar(index,time_ave(:,2),time_std(:,2),'gx-');
hold on
errorbar(index,time_ave(:,3),time_std(:,3),'b.-');
hold on
errorbar(index,time_ave(:,4),time_std(:,4),'k*-');
xlabel('n=x*1e4');ylabel('second');
title('均值比较(无插入排序)');
legend('Heap','Quick','Merge','location','northwest');

subplot(2,2,3);
plot(index,time_var(:,1),'ro-');
hold on
plot(index,time_var(:,2),'gx-');
hold on
plot(index,time_var(:,3),'b.-');
hold on
plot(index,time_var(:,4),'k*-')
xlabel('n=x*1e4');ylabel('Var');
title('方差比较');
legend('Insert','Heap','Quick','Merge','location','northwest');

subplot(2,2,4);
plot(index,time_var(:,2),'gx-');
hold on
plot(index,time_var(:,3),'b.-');
hold on
plot(index,time_var(:,4),'k*-');
xlabel('n=x*1e4');ylabel('Var');
title('方差比较(无插入排序)');
legend('Heap','Quick','Merge','location','northwest');

% %% 线性坐标比较
% figure(1)
% errorbar(index,time_ave(:,1),time_std(:,1),'ro-');
% hold on
% errorbar(index,time_ave(:,2),time_std(:,2),'gx-');
% hold on
% errorbar(index,time_ave(:,3),time_std(:,3),'b.-');
% hold on
% errorbar(index,time_ave(:,4),time_std(:,4),'k*-');
% xlabel('n=x*1e4');ylabel('second');
% title('均值比较');
% legend('Insert','Heap','Quick','Merge','location','northwest');
% 
% %% 线性坐标比较（无插入排序）
% figure(4)
% % plot(index,time_ave(:,2),'gx-');
% % hold on
% % plot(index,time_ave(:,3),'b.-');
% % hold on
% % plot(index,time_ave(:,4)),'k*-';
% errorbar(index,time_ave(:,2),time_std(:,2),'gx-');
% hold on
% errorbar(index,time_ave(:,3),time_std(:,3),'b.-');
% hold on
% errorbar(index,time_ave(:,4),time_std(:,4),'k*-');
% 
% %% 仅方差
% figure(2)
% plot(index,time_var(:,1),'ro-');
% hold on
% plot(index,time_var(:,2),'gx-');
% hold on
% plot(index,time_var(:,3),'b.-');
% hold on
% plot(index,time_var(:,4),'k*-');
% 
% %% 仅方差（无插入排序）
% figure(3)
% plot(index,time_var(:,2),'gx-');
% hold on
% plot(index,time_var(:,3),'b.-');
% hold on
% plot(index,time_var(:,4),'k*-');
% 
% 
% %% 对数坐标比较（无插入排序）
% index=log2(index.*50000);
% figure(5)
% plot(index,time_ave(:,2),'gx-');
% hold on
% plot(index,time_ave(:,3),'b.-');
% hold on
% plot(index,time_ave(:,4),'k*-');
% 

