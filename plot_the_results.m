clear all
close all

num_samples=40;
total_dur=160;
FileName1 = sprintf('desired_samples__samples=%d_total_dur=%d.txt',num_samples,total_dur)
FileName2 = sprintf('errors_per_sample_samples=%d_total_dur=%d.txt',num_samples,total_dur)
FileName3 = sprintf('real_samples__samples=%d_total_dur=%d.txt',num_samples,total_dur)

log_desired = fileread(FileName1);
log_error = fileread(FileName2);
log_real = fileread(FileName3);


log_split = strsplit(log_desired,'\n');
log_desired_arr = zeros(1,length(log_split));
for i=1:length(log_desired_arr)
    log_desired_arr(i) = str2double(cell2mat(log_split(i)));
end
figure;
plot(log_desired_arr,'r');

log_split_2 = strsplit(log_real,'\n');
log_real_arr = zeros(1,length(log_split_2));
for i=1:length(log_real_arr)
    log_real_arr(i) = str2double(cell2mat(log_split_2(i)));
end


hold on
plot(log_real_arr,'o');

title('real and desired samples')

log_split_3 = strsplit(log_error,'\n');
log_error_arr = zeros(1,length(log_split_3));
<<<<<<< HEAD
figure 
plot(log_error_arr,'bo');
=======
figure
plot(log_error_arr,'b');
>>>>>>> e64d4a0b238332b8709bc2345eeeb16f44e5cbbe
for i=1:length(log_error_arr)
    log_error_arr(i) = str2double(cell2mat(log_split_3(i)));
end
hold on
plot(log_error_arr,'ro');
title('errors real vs desired timestamp')
