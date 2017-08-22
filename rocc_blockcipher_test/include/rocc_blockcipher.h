#ifndef __ROCC_BLOCKCIPHER_H__
#define __ROCC_BLOCKCIPHER_H__

#include "custom.h"
#include "asm_util.h"

/*
 *  |    9     |    8   | 7 .. 2 | 1 .. 0  |
 *  | MODE_OFB | CIPHER | ROUNDS | KEY SIZE|
 */
#define ROCC_READ     (0)
#define ROCC_WRITE    (1)
#define ROCC_LOAD     (2)
#define ROCC_STORE    (3)
#define ROCC_COMPUTE  (4)

#define ROCC_KEY_REG_BASE     (0)
#define ROCC_IV_REG_BASE      (8)
#define ROCC_CFG_REG          (16)
#define ROCC_CIPHER_BASE      (12)
#define ROCC_MSG_SIZE_REG     (17)
#define ROCC_PLAIN_ADDR_REG   (18)
#define ROCC_CIPHER_ADDR_REG  (19)
#define ROCC_BLOCK_CNT_REG    (30)
#define ROCC_STATUS_REG       (31)

                             // 0000100101
#define ROCC_AES128_OFB_CFG   0b1000100101
#define ROCC_AES192_OFB_CFG   0b1000101110
#define ROCC_AES256_OFB_CFG   0b1000110111

#define ROCC_AES128_ECB_CFG   0b0000100101
#define ROCC_AES192_ECB_CFG   0b0000101110 
#define ROCC_AES256_ECB_CFGi  0b0000110111

#define ROCC_PRES80_OFB_CFG   0b1110000000
#define ROCC_PRES128_OFB_CFG  0b1110000001

#define ROCC_PRES80_ECB_CFG   0b0110000000 
#define ROCC_PRES128_ECB_CFG  0b0110000001

#define ROCC_CONFIGURE(cfg_word) \
  custom0_rs1(ROCC_WRITE, ROCC_CFG_REG, cfg_word, 0)

#define ROCC_WRITE_KEY_AES128(key) \
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 0, key[0], 0); \
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 1, key[1], 0); \
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 2, key[2], 0); \
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 3, key[3], 0) \


#define ROCC_WRITE_KEY_AES192(key) \
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 0, key[0], 0);  \
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 1, key[1], 0);  \
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 2, key[2], 0);  \
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 3, key[3], 0);  \
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 4, key[4], 0);  \
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 5, key[5], 0)

#define ROCC_WRITE_KEY_AES256(key) \
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 0, key[0], 0);  \
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 1, key[1], 0);  \
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 2, key[2], 0);  \
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 3, key[3], 0);  \
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 4, key[4], 0);  \
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 5, key[5], 0);  \
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 6, key[6], 0);  \
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 7, key[7], 0)   


#define ROCC_WRITE_KEY_PRES128(key) \
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 0, key[0], 0);\
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 1, key[1], 0);\
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 2, key[2], 0);\
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 3, key[3], 0)


#define ROCC_WRITE_KEY_PRES80(key) \
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 0, key[0], 0);\
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 1, key[1], 0)

#define ROCC_ENC() \
  custom0(ROCC_COMPUTE, 0,0,0)

static inline void rocc_configure(unsigned int cfg_word){
  custom0_rs1(ROCC_WRITE, ROCC_CFG_REG, cfg_word, 0);
} 

static inline void rocc_enc(){
  custom0(ROCC_COMPUTE, 0,0,0);
}

static inline void rocc_set_msg_size(unsigned int size){
  custom0_rs1(ROCC_WRITE, ROCC_MSG_SIZE_REG, size, 0);
}

static inline void rocc_set_plain_addr(unsigned int *plain){
  custom0_rs1(ROCC_WRITE, ROCC_PLAIN_ADDR_REG, (unsigned int)plain, 0);
}

static inline void rocc_set_cipher_addr(unsigned int *cipher){
  custom0_rs1(ROCC_WRITE, ROCC_CIPHER_ADDR_REG, (unsigned int)cipher, 0);
}

static void rocc_wait_end_of_encryption(){
  unsigned int k;
  
  k = custom0_rd(ROCC_READ, k, 0,0);
  if( k == 0)
    NOP();
}


static inline unsigned int rocc_read_block_cnt(){
  unsigned int var;
  var = custom0_rd(ROCC_READ, var, ROCC_BLOCK_CNT_REG,  0);
  return var;
}

//extern inline void rocc_configure(unsigned int);
//extern inline void rocc_enc();

void rocc_write_key_aes128(unsigned int [static 4]);
void rocc_write_key_aes192(unsigned int [static 6]);
void rocc_write_key_aes256(unsigned int [static 8]);

void rocc_write_key_pres80( unsigned int [static 3]);
void rocc_write_key_pres128(unsigned int [static 4]);

void rocc_write_block_128(unsigned int [static 4]);
void rocc_write_block_64(unsigned int [static 2]); 

void rocc_read_cipher_128(unsigned int [static 4]);
void rocc_read_cipher_64(unsigned int [static 2]);
                                        
  
#endif
