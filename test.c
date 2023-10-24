#include <stdio.h>
#include <time.h>
#include <sys/timeb.h>
#include <string.h>
#include <stdlib.h>

int main() {
    // 获取当前时间
    struct timeb tb;
    ftime(&tb);
    struct tm *local_time = localtime(&tb.time);

    // 格式化当前时间为字符串
    char time_str[24];
    strftime(time_str, sizeof(time_str), "%Y%m%d_%H%M%S", local_time);

    // 将毫秒拼接到时间字符串
    char ms_str[5];
    sprintf(ms_str, "_%03d", tb.millitm);
    
    strcat(time_str, ms_str);

    // 构建文件名
    char filename[30];
    sprintf(filename, "out_%s.cfg", time_str);

    // 创建并打开文件
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("无法创建文件！\n");
        return 1;
    }

    // 写入文件内容
    fprintf(file, "这是一个示例文件。\n");

    // 关闭文件
    fclose(file);

    printf("已成功生成文件：%s\n", filename);

    return 0;
}