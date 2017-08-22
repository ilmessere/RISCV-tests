#include "asm_util.h"
#include "rocc_blockcipher.h"

/**********************************/ 
/*      global variables         **/ 
/**********************************/ 
unsigned int iv[]     = {0x00010203, 0x04050607, 0x08090a0b, 0x0c0d0e0f};

unsigned int key128[] = {0x2b7e1516, 0x28aed2a6, 0xabf71588, 0x09cf4f3c};

unsigned int key192[] = {0x8e73b0f7, 0xda0e6452, 0xc810f32b, 0x809079e5, 0x62f8ead2, 0x522c6b7b};

unsigned int key256[] = {0x603deb10, 0x15ca71be, 0x2b73aef0, 0x857d7781, 0x1f352c07, 0x3b6108d7, 0x2d9810a3, 0x0914dff4};

unsigned int plain[]  = {0x6bc1bee2, 0x2e409f96, 0xe93d7e11, 0x7393172a,
                         0xae2d8a57, 0x1e03ac9c, 0x9eb76fac, 0x45af8e51, 
                         0x30c81c46, 0xa35ce411, 0xe5fbc119, 0x1a0a52ef, 
                         0xf69f2445, 0xdf4f9b17, 0xad2b417b, 0xe66c3710}; 

unsigned int cipher_aes128_ofb[] = {
                         0x3b3fd92e, 0xb72dad20, 0x333449f8, 0xe83cfb4a, 
                         0x7789508d, 0x16918f03, 0xf53c52da, 0xc54ed825, 
                         0x9740051e, 0x9c5fecf6, 0x4344f7a8, 0x2260edcc, 
                         0x304c6528, 0xf659c778, 0x66a510d9, 0xc1d6ae5e};

unsigned int cipher_aes192_ofb[] = {
                        0xcdc80d6f, 0xddf18cab, 0x34c25909, 0xc99a4174,
                        0xfcc28b8d, 0x4c63837c, 0x09e81700, 0xc1100401,
                        0x8d9a9aea, 0xc0f6596f, 0x559c6d4d, 0xaf59a5f2,
                        0x6d9f2008, 0x57ca6c3e, 0x9cac524b, 0xd9acc92a};

unsigned int cipher_aes256_ofb[] = {
                        0xdc7e84bf, 0xda79164b, 0x7ecd8486, 0x985d3860, 
                        0x4febdc67, 0x40d20b3a, 0xc88f6ad8, 0x2a4fb08d,
                        0x71ab47a0, 0x86e86eed, 0xf39d1c5b, 0xba97c408,
                        0x0126141d, 0x67f37be8, 0x538f5a8b, 0xe740e484};

unsigned int cipher_aes128_ecb[] = {
                        0x3ad77bb4, 0x0d7a3660, 0xa89ecaf3, 0x2466ef97,  
                        0xf5d3d585, 0x03b9699d, 0xe785895a, 0x96fdbaaf,
                        0x43b1cd7f, 0x598ece23, 0x881b00e3, 0xed030688,
                        0x7b0c785e, 0x27e8ad3f, 0x82232071, 0x04725dd4};

unsigned int cipher_res[16];

/**********************************/ 
/*    function declarations       */ 
/**********************************/ 
void setup_commons();
void test_aes128_ecb();
void test_aes128_ofb();
void test_aes192_ofb();
void test_aes256_ofb();
void test_res(unsigned int*, unsigned int*, unsigned int);


/**********************************/ 
int main(){
  unsigned int i; 
  unsigned int block_cnt = 0;

  while(1){
    
    /**********************************/ 
    /*  test single block encryption  */ 
    /**********************************/ 

    test_aes128_ecb(); 

    NOP10() 
    NOP10()


    /**********************************/ 
    /*  test OFB mode of encryption   */ 
    /**********************************/ 
    
    setup_commons();     

    NOP10()
    NOP10()

    test_aes128_ofb();   

    NOP10()
    NOP10()

    test_aes192_ofb();  

    NOP10()
    NOP10()

    test_aes256_ofb();  
    
    NOP10()
    NOP10()
  }
  return 0;
}


/**********************************/ 
/*      function definitions      */
/**********************************/ 

void setup_commons(){
    rocc_set_msg_size(16);
    rocc_set_plain_addr(plain);
    rocc_set_cipher_addr(cipher_res);
    rocc_write_block_128(iv);
}

void test_aes128_ofb(){
    rocc_configure(ROCC_AES128_OFB_CFG);
    rocc_write_key_aes128(key128);
    rocc_enc();
    rocc_wait_end_of_encryption();
    test_res(cipher_res, cipher_aes128_ofb, 16);
}

void test_aes192_ofb(){
    rocc_configure(ROCC_AES192_OFB_CFG);
    rocc_write_key_aes192(key192);
    rocc_enc();
    rocc_wait_end_of_encryption();
    test_res(cipher_res, cipher_aes192_ofb, 16);
}

void test_aes256_ofb(){
    rocc_configure(ROCC_AES256_OFB_CFG);
    rocc_write_key_aes256(key256);
    rocc_enc();
    rocc_wait_end_of_encryption();
    test_res(cipher_res, cipher_aes256_ofb, 16);
}

void test_aes128_ecb(){
    unsigned int i;
    rocc_configure(ROCC_AES128_ECB_CFG);
    ROCC_WRITE_KEY_AES128(key128);
    for( i = 0; i<4; i++){
      rocc_write_block_128(&plain[i*4]); 
      ROCC_ENC();
      rocc_read_cipher_128(&cipher_res[i*4]);
    }
    test_res(cipher_aes128_ecb, cipher_res, 16);
}

void test_res(unsigned int *a, unsigned int *b, unsigned int size){
      unsigned int i;

      for(i=0; i<size; i++){
        if(a[i] != b[i]) while(1);
      }
}
