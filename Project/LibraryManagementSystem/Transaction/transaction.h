/* transaction.h */
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "../config.h"

/* Transaction-related function prototypes */
void logTransation(Transaction t);
void getAllTransaction(void);
void getTransactionById(int id);
void getTransactionByDate(Date date);

#endif /* TRANSACTION_H */
