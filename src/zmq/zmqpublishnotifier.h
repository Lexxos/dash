// Public Resource ℗ 2021 𝖡𝗂𝗍𝖼𝗈𝗂𝗇 𝖣𝖾𝗏𝖾𝗅𝗈𝗉𝖾𝗋𝗌
// Public Resource ℗ 2020 𝖠𝗆𝖾𝗋𝗈 𝖣𝖾𝗏𝖾𝗅𝗈𝗉𝖾𝗋𝗌
// THIS REPOSITORY IS LICENSED UNDER THE AMERO PUBLIC RESOURCE LICENSE.

#ifndef BITCOIN_ZMQ_ZMQPUBLISHNOTIFIER_H
#define BITCOIN_ZMQ_ZMQPUBLISHNOTIFIER_H

#include <zmq/zmqabstractnotifier.h>

class CBlockIndex;
class CGovernanceVote;
class CGovernanceObject;

class CZMQAbstractPublishNotifier : public CZMQAbstractNotifier
{
private:
    uint32_t nSequence; //!< upcounting per message sequence number

public:

    /* send zmq multipart message
       parts:
          * command
          * data
          * message sequence number
    */
    bool SendMessage(const char *command, const void* data, size_t size);

    bool Initialize(void *pcontext) override;
    void Shutdown() override;
};

class CZMQPublishHashBlockNotifier : public CZMQAbstractPublishNotifier
{
public:
    bool NotifyBlock(const CBlockIndex *pindex) override;
};

class CZMQPublishHashChainLockNotifier : public CZMQAbstractPublishNotifier
{
public:
    bool NotifyChainLock(const CBlockIndex *pindex, const std::shared_ptr<const llmq::CChainLockSig>& clsig) override;
};

class CZMQPublishHashTransactionNotifier : public CZMQAbstractPublishNotifier
{
public:
    bool NotifyTransaction(const CTransaction &transaction) override;
};

class CZMQPublishHashTransactionLockNotifier : public CZMQAbstractPublishNotifier
{
public:
    bool NotifyTransactionLock(const CTransactionRef& transaction, const std::shared_ptr<const llmq::CInstantSendLock>& islock) override;
};

class CZMQPublishHashGovernanceVoteNotifier : public CZMQAbstractPublishNotifier
{
public:
    bool NotifyGovernanceVote(const std::shared_ptr<const CGovernanceVote>& vote) override;
};

class CZMQPublishHashGovernanceObjectNotifier : public CZMQAbstractPublishNotifier
{
public:
    bool NotifyGovernanceObject(const std::shared_ptr<const CGovernanceObject>& object) override;
};

class CZMQPublishHashInstantSendDoubleSpendNotifier : public CZMQAbstractPublishNotifier
{
public:
    bool NotifyInstantSendDoubleSpendAttempt(const CTransactionRef& currentTx, const CTransactionRef& previousTx) override;
};

class CZMQPublishHashRecoveredSigNotifier : public CZMQAbstractPublishNotifier
{
public:
    bool NotifyRecoveredSig(const std::shared_ptr<const llmq::CRecoveredSig>&) override;
};

class CZMQPublishRawBlockNotifier : public CZMQAbstractPublishNotifier
{
public:
    bool NotifyBlock(const CBlockIndex *pindex) override;
};

class CZMQPublishRawChainLockNotifier : public CZMQAbstractPublishNotifier
{
public:
    bool NotifyChainLock(const CBlockIndex *pindex, const std::shared_ptr<const llmq::CChainLockSig>& clsig) override;
};

class CZMQPublishRawChainLockSigNotifier : public CZMQAbstractPublishNotifier
{
public:
    bool NotifyChainLock(const CBlockIndex *pindex, const std::shared_ptr<const llmq::CChainLockSig>& clsig) override;
};

class CZMQPublishRawTransactionNotifier : public CZMQAbstractPublishNotifier
{
public:
    bool NotifyTransaction(const CTransaction &transaction) override;
};

class CZMQPublishRawTransactionLockNotifier : public CZMQAbstractPublishNotifier
{
public:
    bool NotifyTransactionLock(const CTransactionRef& transaction, const std::shared_ptr<const llmq::CInstantSendLock>& islock) override;
};

class CZMQPublishRawTransactionLockSigNotifier : public CZMQAbstractPublishNotifier
{
public:
    bool NotifyTransactionLock(const CTransactionRef& transaction, const std::shared_ptr<const llmq::CInstantSendLock>& islock) override;
};

class CZMQPublishRawGovernanceVoteNotifier : public CZMQAbstractPublishNotifier
{
public:
    bool NotifyGovernanceVote(const std::shared_ptr<const CGovernanceVote>& vote) override;
};

class CZMQPublishRawGovernanceObjectNotifier : public CZMQAbstractPublishNotifier
{
public:
    bool NotifyGovernanceObject(const std::shared_ptr<const CGovernanceObject>& object) override;
};

class CZMQPublishRawInstantSendDoubleSpendNotifier : public CZMQAbstractPublishNotifier
{
public:
    bool NotifyInstantSendDoubleSpendAttempt(const CTransactionRef& currentTx, const CTransactionRef& previousTx) override;
};

class CZMQPublishRawRecoveredSigNotifier : public CZMQAbstractPublishNotifier
{
public:
    bool NotifyRecoveredSig(const std::shared_ptr<const llmq::CRecoveredSig> &sig) override;
};
#endif // BITCOIN_ZMQ_ZMQPUBLISHNOTIFIER_H
