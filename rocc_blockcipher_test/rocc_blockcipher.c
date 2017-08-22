#include "rocc_blockcipher.h"
/*
void rocc_configure(unsigned int cfg_word){
  custom0_rs1(ROCC_WRITE, ROCC_CFG_REG, cfg_word, 0);
} 

void rocc_enc(){
  custom0(ROCC_COMPUTE, 0,0,0);
}
*/
void rocc_write_key_aes128(unsigned int key[static 4]){
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 0, key[0], 0);
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 1, key[1], 0);
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 2, key[2], 0);
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 3, key[3], 0);
}

void rocc_write_key_aes192(unsigned int key[static 6]){
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 0, key[0], 0);
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 1, key[1], 0);
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 2, key[2], 0);
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 3, key[3], 0);
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 4, key[4], 0);
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 5, key[5], 0);
}

void rocc_write_key_aes256(unsigned int key[static 8]){
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 0, key[0], 0);
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 1, key[1], 0);
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 2, key[2], 0);
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 3, key[3], 0);
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 4, key[4], 0);
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 5, key[5], 0);
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 6, key[6], 0);
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 7, key[7], 0);
}

void rocc_write_key_pres128(unsigned int key[static 4]){
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 0, key[0], 0);
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 1, key[1], 0);
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 2, key[2], 0);
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 3, key[3], 0);
}

void rocc_write_key_pres80(unsigned int key[static 3]){
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 0, key[0], 0);
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 1, key[1], 0);
  custom0_rs1(ROCC_WRITE, ROCC_KEY_REG_BASE + 2, key[2], 0);
}


void rocc_write_block_128(unsigned int iv[static 4]){
  custom0_rs1(ROCC_WRITE, ROCC_IV_REG_BASE + 0, iv[0], 0);
  custom0_rs1(ROCC_WRITE, ROCC_IV_REG_BASE + 1, iv[1], 0);
  custom0_rs1(ROCC_WRITE, ROCC_IV_REG_BASE + 2, iv[2], 0);
  custom0_rs1(ROCC_WRITE, ROCC_IV_REG_BASE + 3, iv[3], 0);
}


void rocc_write_block_64(unsigned int iv[static 2]){
  custom0_rs1(ROCC_WRITE, ROCC_IV_REG_BASE + 0, iv[0], 0);
  custom0_rs1(ROCC_WRITE, ROCC_IV_REG_BASE + 1, iv[1], 0);
}

void rocc_read_cipher_64(unsigned int dst[static 2]){
  dst[0] = custom0_rd(ROCC_READ, dst[0], ROCC_CIPHER_BASE, 0);
  dst[1] = custom0_rd(ROCC_READ, dst[1], ROCC_CIPHER_BASE + 1, 0);
}

void rocc_read_cipher_128(unsigned int dst[static 4]){
  dst[0] = custom0_rd(ROCC_READ, dst[0], ROCC_CIPHER_BASE + 0,  0);
  dst[1] = custom0_rd(ROCC_READ, dst[1], ROCC_CIPHER_BASE + 1,  0);
  dst[2] = custom0_rd(ROCC_READ, dst[2], ROCC_CIPHER_BASE + 2,  0);
  dst[3] = custom0_rd(ROCC_READ, dst[3], ROCC_CIPHER_BASE + 3,  0);
}


