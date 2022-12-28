#ifndef HIMITSU_SECURITY
#define HIMITSU_SECURITY

#include <string.h>

#define ENC_MAX         128

#define IV_LEN          0x10  // 127 - bits, 16 bytes. (initialization vector)
#define AES_LEN         0x20  // 256 - bits, 32 bytes.
#define SHA256_LEN      0x20  // 256 - bits, 32 bytes. 

namespace Himitsu {
    
    class Security {
        private:
            int            plock_enc_size;                // The actual size of the encrypted password.
            unsigned char  plock_enc[ENC_MAX];            // Encrypted lock (a.k.a master password).
            unsigned char *plock_key;                     // one-time encryption key for lock.
            unsigned char *plock_iv;                      // one-time encryption key iv, for AES.
            
        public:
            Security();
            ~Security();

            /**
             * *get_sha256* return the sha256 hash of msg.
             * @param msg The message to hash.
             * @param s_msg The size of the message.
             */
            static const unsigned char *get_sha256(const char *msg, size_t s_msg);
            
            /**
             * *encrypt_data* Enccypts data using AES 256 bit.
             * @param dst The encrypted data.
             * @param data The data to ecnrypt.
             * @param size The size of the data.
             * @param key The key to use, to encrypt.
             * @param iv The initialization vector.
             */
            static int encrypt_data(unsigned char *dst, const unsigned char *data, 
                                    int size, const unsigned char *key, const unsigned char *iv);
            
            /**
             * *encrypt_data* Decrypts data using AES 256 bit.
             * @param dst The decrepted data.
             * @param data The data to decrept.
             * @param size The size of the data.
             * @param key The key to use, to encrypt.
             * @param iv The initialization vector.
             */
            static int decrypt_data(unsigned char *dst, const unsigned char *data, 
                                    int size, const unsigned char *key, const unsigned char *iv);

            /**
             * The functions below is all the informations
             * that needed in order to decrypt the master 
             * password.
             */
            /**
             * @return the size of the encypted 
             * master password.
             */
            int get_master_pwd_size();

            /**
             * @return the encypted master password.
             */
            const unsigned char *get_master_pwd();

            /**
             * @return the key used to enctypt the 
             * master password.
             */
            const unsigned char *get_master_used_key();

            /**
             * @return the initialization vector used
             * to ecnrypt the master password.
             */
            const unsigned char *get_master_used_iv();


            /**
             * @return random bytes of length @len
             */
            static unsigned char *get_random_bytes(int len);
            
            /**
             * @return an random initialization vector.
             */
            static unsigned char *get_aes_iv(); 
    };
}

#endif

