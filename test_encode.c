#include <stdio.h>
#include "encode.h"
#include "decode.h"
#include "types.h"

int main(int argc ,char *argv[])
{
    if(argc<3)
    {
        printf("Invalid Input\n");
        printf("For encoding : \n ./a.out -e beautiful.bmp secret.txt stego.bmp\n");
        printf("For decoding : \n ./a.out -d stego.bmp [decode.txt]\n");
        return -1;
    }
    EncodeInfo E1;
    DecodeInfo D1;
    int res=check_operation_type(argv);
    
        if(res==e_encode)
        {
            printf("selected Encoding\n");
            if(read_and_validate_encode_args(argv,&E1)==e_success)
            {
                printf("INFO :Read and validate encode args are success\n");
                if(do_encoding(&E1)==e_success)
                {
                    printf("Info:Encoding is success\n");
                }
                else
                {
                    printf("Failed to encode\n");
                    return 0;

                }

            }
            else
            {
                printf("ERROR :Read and validate encode args are failure\n");
                return 0;  
            }
        }
        else if(res==e_decode)
        {
            printf("selected Decoding\n");
            if(read_and_validate_decode_args(argv,&D1)==d_success)
            {
                printf("INFO :Read and validate decode stego.bmp&secret data are success\n");
                if(do_decoding(&D1)==d_success)
                {
                    printf("Info:Deccoding is success\n");
                }
                else
                {
                    printf("Failed to decode\n");
                    return 0;

                }

            }
            else
            {
                printf("ERROR :Read and validate encode args are failure\n");
                return 0;  
            }

        }
        else
        {
            printf("Invalid input\n");
        }
    

    return 0;
}
OperationType check_operation_type(char *argv[])
{
    if(strcmp(argv[1],"-e")==0)
    {
        return e_encode;
    }
    else if(strcmp(argv[1],"-d")==0)
    {
        return e_decode;
    }
    else
    {
        return e_unsupported;

    }
}
