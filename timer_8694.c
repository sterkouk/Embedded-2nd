#include <signal.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>



int main(int argc, char *argv[]) {
    int i=0,j=0,k;
    struct timeval start ;
    int num_samples,total_time,calibrate;
    if (argc >= 3){
        num_samples=atoi(argv[1]);
        total_time= atoi(argv[2]);
        calibrate= atoi(argv[3]);
    }else{
      printf("\n Please provide the number of samples ,the total time and the calibration parameter \n");
      exit(1);
    }
    int dur=(int)total_time/num_samples;

    long long *TIMES=(long long *)malloc(sizeof(long long)*num_samples);
    long long *error_arr=(long long *)malloc(sizeof(long long)*num_samples);
    long long *desired_arr=(long long *)malloc(sizeof(long long)*num_samples);


    for (j = 0; j < num_samples; j++) {
        TIMES[j]=0;
        error_arr[j]=0;
        desired_arr[i]=0;
     }
     long long diff=0,micro_time=0,micro_time_sec=0;
     long long s1=0,s2=0,error=0,init=0,dval;

     printf("\n Number of samples: %d \n",num_samples);
     printf("\n Sampling interval: %d \n",dur);
     printf("\n Calibration Parameter: %d \n",calibrate); //for calibration on different machines
     printf("\n------------------------\n");

     for(i=0;i<num_samples;i++){
            gettimeofday(&start, NULL);
            TIMES[i]=start.tv_sec*1000000 + start.tv_usec; // caculate microseconds
            if(i>0){
                  dval=init+i*(dur)*1000000;
                  error=TIMES[i]-dval;
                  error_arr[i]=error;
                  desired_arr[i]=dval;
                //printf("error:%lld\n",error );
                //printf("desired:%lld\n",dval );
             }else if (i==0){
                init=TIMES[i];
                desired_arr[i]=init;
             }
            micro_time=(dur-1)*1000000 +999995-calibrate-error;
            usleep(micro_time);
      }



    printf("\n\nPrinting time stamps:\n\n");

    for( k = 0; k < num_samples; k++){
      printf("Timestamp i=%d  is:  %lld\n",k,TIMES[k]);
    }
    for( k = 0; k < num_samples-1; k++){
      printf("error =%lld  \n",error_arr[k]);
    }

    FILE *fp1=NULL;
    FILE *fp2=NULL;
    FILE *fp3=NULL;
    char errors_file[100];
    char desired_file[100];
    char real_file[100];
    sprintf(errors_file,"errors_per_sample_samples=%d_total_dur=%d.txt", num_samples, total_time);
    sprintf(desired_file,"desired_samples__samples=%d_total_dur=%d.txt", num_samples, total_time);
    sprintf(real_file,"real_samples__samples=%d_total_dur=%d.txt", num_samples, total_time);
    fp1=fopen(errors_file,"w");
    fp2=fopen(desired_file,"w");
    fp3=fopen(real_file,"w");

    printf("\nDIFFERENCES BETWEEN TWO NEIGHBORS\n\n");
    for( k = 0; k < num_samples; k++){
      printf("diafora tou i=%d  me ton i=%d einai:  %lld\n",k,k+1, TIMES[k+1]-TIMES[k]);
      fprintf(fp1,"%lld\n",error_arr[k]);
      fprintf(fp2,"%lld\n",desired_arr[k]);
      fprintf(fp3,"%lld\n",TIMES[k]);
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    printf("\nFirst Time stamp: %lld\n\n",TIMES[0]);
    printf("\nLast Time stamp: %lld\n\n",TIMES[num_samples-1]);

    printf("\nShift from start to end in microseconds : %lld \n\n ",(TIMES[num_samples-1]-TIMES[0]) );
    printf("\nShift from start to end in miliseconds: %lld\n\n",(TIMES[num_samples-1]-TIMES[0])/1000);
    printf("\nShift from start to end in seconds: %lld\n\n",(TIMES[num_samples-1]-TIMES[0])/1000000);
    printf("\nError in microseconds: %lld\n\n",-(num_samples-1)*dur*1000000+(TIMES[num_samples-1]-TIMES[0]));

    return 0;
}
