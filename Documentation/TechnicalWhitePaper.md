# BASIC CHAIN Technical White Paper v1

**MAY 16, 2018**

**Abstract:** The BASIC CHAIN software introduces a new AI Powered blockchain architecture designed to enable vertical and horizontal scaling of decentralized applications. This is achieved by creating an operating system-like construct upon which applications can be built. The software provides accounts, authentication, databases, asynchronous communication, and the scheduling of applications across many of CPU cores or clusters. The resulting technology is a blockchain architecture that may ultimately scale to millions of transactions per second, eliminates user fees, and allows for quick and easy deployment and maintenance of decentralized applications, in the context of a governed blockchain.

Copyright © 2018 LoopBlock Network

Without permission, anyone may use, reproduce or distribute any material in this white paper for non-commercial and educational use (i.e., other than for a fee or for commercial purposes) provided that the original source and the applicable copyright notice are cited.


**DISCLAIMER:** This BASIC CHAIN Technical White Paper v1 is for information purposes only. LoopBlock Network does not guarantee the accuracy of or the conclusions reached in this white paper, and this white paper is provided “as is”. LoopBlock Network does not make and expressly disclaims all representations and warranties, express, implied, statutory or otherwise, whatsoever, including, but not limited to: (i) warranties of merchantability, fitness for a particular purpose, suitability, usage, title or noninfringement; (ii) that the contents of this white paper are free from error; and (iii) that such contents will not infringe third-party rights. LoopBlock Network and its affiliates shall have no liability for damages of any kind arising out of the use, reference to, or reliance on this white paper or any of the content contained herein, even if advised of the possibility of such damages. In no event will LoopBlock Network or its affiliates be liable to any person or entity for any damages, losses, liabilities, costs or expenses of any kind, whether direct or indirect, consequential, compensatory, incidental, actual, exemplary, punitive or special for the use of, reference to, or reliance on this white paper or any of the content contained herein, including, without limitation, any loss of business, revenues, profits, data, use, goodwill or other intangible losses.


# Background

Blockchain technology was introduced in 2008 with the launch of the Bitcoin currency, and since then entrepreneurs and developers have attempted to generalize the technology to support a wider range of applications on a single blockchain platform.

While a number of blockchain platforms have struggled to support functional decentralized applications, application specific blockchains such as the BitShares decentralized exchange (2014) and Steem social media platform (2016) have become heavily used blockchains with tens of thousands of daily active users. They have achieved this by increasing performance to thousands of transactions per second, reducing latency to 1.5 seconds, eliminating per-transaction fees, and providing a user experience similar to those currently provided by existing centralized services.

Existing blockchain platforms are burdened by large fees and limited computational capacity that prevent widespread blockchain adoption.

# Requirements for Blockchain Applications

In order to gain widespread use, applications on the blockchain require a platform that is flexible enough to meet the following requirements:

## Support Millions of Users

Competing with businesses such as eBay, Uber, AirBnB, and Facebook, require blockchain technology capable of handling tens of millions of active daily users. In certain cases, an application may not work unless a critical mass of users is reached and therefore a platform that can handle very large numbers of users is paramount.

## Free Usage

Application developers need the flexibility to offer users free services; users should not have to pay in order to use the platform or benefit from its services. A blockchain platform that is free to use for users will likely gain more widespread adoption. Developers and businesses can then create effective monetization strategies.

## Easy Upgrades and Bug Recovery

Businesses building blockchain based applications need the flexibility to enhance their applications with new features. The platform must support software and smart contract upgrades.

All non-trivial software is subject to bugs, even with the most rigorous of formal verification. The platform must be robust enough to fix bugs when they inevitably occur.

## Low Latency

A good user experience demands reliable feedback with a delay of no more than a few seconds. Longer delays frustrate users and make applications built on a blockchain less competitive with existing non-blockchain alternatives. The platform should support low latency of transactions.

## Sequential Performance

There are some applications that just cannot be implemented with parallel algorithms due to sequentially dependent steps. Applications such as exchanges need enough sequential performance to handle high volumes. Therefore, the platform should support fast sequential performance.

## Parallel Performance

Large scale applications need to divide the workload across multiple CPUs and computers.

# Consensus Algorithm (QUARK-POW/POS)

BASIC-CHAIN software utilizes one of the only known decentralized consensus algorithm proven capable of meeting the performance requirements of applications on the blockchain, [QUARK Proof of Work and Proof of Stake (POW/POS)](https://en.bitcoinwiki.org/wiki/Quark_Algorithm). Quark is an algorithm for mining cryptocurrency based on a one-level hash function, which consists of 9 levels of encryption by six different cryptographic algorithms. Quark is not demanding for large amounts of RAM. Also, the Quark has a high 64-bit protection against hacker attacks. Quark is remarkable for its low power consumption. A distinctive feature of Quark is the parallel use of 6 hash functions, namely:

Grostl;
Blue Midnight Wish;
Keccak;
JH;
Skein;
Blake.
The Quark algorithm is used in consensus-building mechanisms [Proof-of-work](https://en.bitcoinwiki.org/wiki/Proof-of-work) and [Proof-of-stake](https://en.bitcoinwiki.org/wiki/Proof-of-stake) to increase security and certainty while maintaining the health of the cryptocurrency ecosystem. Comparing with the algorithm Bitcoin SHA-256, Quark is protected from the danger of a single point of failure (SPOF – Single Point of Failure), which is able to stop the entire system. If you identify the problem part in the Quark algorithm, the vulnerability can be eliminated by replacing the hash function.

Under normal conditions a QUARK-POW/POS blockchain does not experience any forks because, rather than compete, the miners cooperate to mint blocks. In the event there is a fork, consensus will automatically switch to the longest chain. This method works because the rate at which blocks are added to a blockchain fork is directly correlated to the percentage of miners that share the same consensus. In other words, a blockchain fork with more miners on it will grow in length faster than one with fewer miners. Byzantine Fault Tolerance is added to traditional QUARK-POW/POS by allowing all miners to mint blocks so long as no miner mints two blocks with the same timestamp or the same block height. Once a block receives 3 confirmations the block is deemed irreversible.

## Transaction Confirmation

Typical QUARK-POW/POS blockchains have 100% block mining participation. A transaction can be considered confirmed with 99.9% certainty after an average of 0.25 to 60 seconds from time of broadcast.

In addition to QUARK-POW/POS, BASIC-CHAIN adds asynchronous Byzantine Fault Tolerance (aBFT) for faster achievement of irreversibility. The aBFT algorithm provides 100% confirmation of irreversibility within 1 second.

## Transaction as Proof of Stake (TaPoS)

The BASIC-CHAIN software requires every transaction to include part of the hash of a recent block header. This hash serves two purposes:

1. prevents a replay of a transaction on forks that do not include the referenced block; and
2. signals the network that a particular user and their stake are on a specific fork.

Over time all users end up directly confirming the blockchain which makes it difficult to forge counterfeit chains as the counterfeit would not be able to migrate transactions from the legitimate chain.

# Accounts

The BASIC-CHAIN software permits all accounts to be referenced by a unique human readable name of up to 16 characters in length. The name is chosen by the creator of the account. The account creator must reserve the RAM required to store the new account until the new account stakes tokens to reserve its own RAM.

In a decentralized context, application developers will pay the nominal cost of account creation to sign up a new user. Traditional businesses already spend significant sums of money per customer they acquire in the form of advertising, free services, etc. The cost of funding a new blockchain account should be insignificant in comparison. Fortunately, there is no need to create accounts for users already signed up by another application.

## Actions & Handlers

Each account can send structured Actions to other accounts and may define scripts to handle Actions when they are received. The BASIC-CHAIN software gives each account its own private database which can only be accessed by its own action handlers. Action handling scripts can also send Actions to other accounts. The combination of Actions and automated action handlers is how BASIC-CHAIN defines smart contracts.

To support parallel execution, each account can also define any number of scopes within their database. The block producers will schedule transaction in such a way that there is no conflict over memory access to scopes and therefore they can be executed in parallel.

## Role Based Permission Management

Permission management involves determining whether or not an Action is properly authorized. The simplest form of permission management is checking that a transaction has the required signatures, but this implies that required signatures are already known. Generally, authority is bound to individuals or groups of individuals and is often compartmentalized. The BASIC-CHAIN software provides a declarative permission management system that gives accounts fine grained and high-level control over who can do what and when.

It is critical that authentication and permission management be standardized and separated from the business logic of the application. This enables tools to be developed to manage permissions in a general-purpose manner and also provide significant opportunities for performance optimization.

Every account may be controlled by any weighted combination of other accounts and private keys. This creates a hierarchical authority structure that reflects how permissions are organized in reality and makes multi-user control over accounts easier than ever. Multi-user control is the single biggest contributor to security, and, when used properly, it can greatly reduce the risk of theft due to hacking.

BASIC-CHAIN software allows accounts to define what combination of keys and/or accounts can send a particular Action type to another account. For example, it is possible to have one key for a user's social media account and another for access to the exchange. It is even possible to give other accounts permission to act on behalf of a user's account without assigning them keys.

### Named Permission Levels

<img align="right" src="https://github.com/basicnetwork/basic/blob/master/diagram3.png" width="228.395px" height="300px" />

Using the BASIC-CHAIN software, accounts can define named permission levels each of which can be derived from higher level named permissions. Each named permission level defines an authority; an authority is a threshold multi-signature check consisting of keys and/or named permission levels of other accounts. For example, an account's "Friend" permission level can be set for an Action on the account to be controlled equally by any of the account's friends.

Another example is the Steem and EOS blockchain which has three hard-coded named permission levels: owner, active, and posting. The posting permission can only perform social actions such as voting and posting, while the active permission can do everything except change the owner. The owner permission is meant for cold storage and is able to do everything. The BASIC-CHAIN software generalizes this concept by allowing each account holder to define their own hierarchy as well as the grouping of actions.

### Permission Mapping

BASIC-CHAIN software allows each account to define a mapping between a contract/action or contract of any other account and their own Named Permission Level. For example, an account holder could map the account holder's social media application to the account holder's "Friend" permission group. With this mapping, any friend could post as the account holder on the account holder's social media. Even though they would post as the account holder, they would still use their own keys to sign the Action. This means it is always possible to identify which friends used the account and in what way.

### Evaluating Permissions

When delivering an Action of type "**Action**", from **@ada** to **@obi** the BASIC-CHAIN software will first check to see if **@ada** has defined a permission mapping for **@obi.groupa.subgroup.Action**. If nothing is found then a mapping for **@obi.groupa.subgroup** then **@obi.groupa**, and lastly **@obi** will be checked. If no further match is found, then the assumed mapping will be to the named permission group **@ada.active**.

Once a mapping is identified then signing authority is validated using the threshold multi-signature process and the authority associated with the named permission. If that fails, then it traverses up to the parent permission and ultimately to the owner permission, **@ada.owner**.

<img align="center" src="https://github.com/basicnetwork/basic/blob/master/Documentation/diagram2grayscale2.jpg" width="845.85px" height="500px" />

#### Default Permission Groups

The BASIC-CHAIN technology also allows all accounts to have an "owner" group which can do everything, and an "active" group which can do everything except change the owner group. All other permission groups are derived from "active".

#### Parallel Evaluation of Permissions

The permission evaluation process is "read-only" and changes to permissions made by transactions do not take effect until the end of a block. This means that all keys and permission evaluation for all transactions can be executed in parallel. Furthermore, this means that a rapid validation of permission is possible without starting costly application logic that would have to be rolled back. Lastly, it means that transaction permissions can be evaluated as pending transactions are received and do not need to be re-evaluated as they are applied.

All things considered, permission verification represents a significant percentage of the computation required to validate transactions. Making this a read-only and trivially parallelizable process enables a dramatic increase in performance.

When replaying the blockchain to regenerate the deterministic state from the log of Actions there is no need to evaluate the permissions again. The fact that a transaction is included in a known good block is sufficient to skip this step. This dramatically reduces the computational load associated with replaying an ever growing blockchain.

## Actions with Mandatory Delay

Time is a critical component of security. In most cases, it is not possible to know if a private key has been stolen until it has been used. Time based security is even more critical when people have applications that require keys be kept on computers connected to the internet for daily use. The BASIC-CHAIN software enables application developers to indicate that certain Actions must wait a minimum period of time after being included in a block before they can be applied. During this time, they can be cancelled.

Users can then receive notice via email or text message when one of these Actions is broadcast. If they did not authorize it, then they can use the account recovery process to recover their account and retract the Action.

The required delay depends upon how sensitive an operation is. Paying for a coffee might have no delay and be irreversible in seconds, while buying a house may require a 72 hour clearing period. Transferring an entire account to new control may take up to 30 days. The exact delays are chosen by application developers and users.

## Recovery from Stolen Keys

The BASIC-CHAIN software provides users a way to restore control of their account when keys are stolen. An account owner can use any owner key that was active in the last 30 days along with approval from their designated account recovery partner to reset the owner key on their account. The account recovery partner cannot reset control of the account without the help of the owner.

There is nothing for the hacker to gain by attempting to go through the recovery process because they already "control" the account. Furthermore, if they did go through the process, the recovery partner would likely demand identification and multi-factor authentication (phone and email). This would likely compromise the hacker or gain the hacker nothing in the process.

This process is also very different from a simple multi-signature arrangement. With a multi-signature transaction, another entity is made a party to every transaction that is executed. By contrast, with the recovery process the recovery partner is only a party to the recovery process and has no power over the day-to-day transactions. This dramatically reduces costs and legal liabilities for everyone involved.

# Deterministic Parallel Execution of Applications

Blockchain consensus depends upon deterministic (reproducible) behavior. This means all parallel execution must be free from the use of mutexes or other locking primitives. Without locks there must be some way to guarantee that transactions that may be executed in parallel do not create non-deterministic results.

In a BASIC-CHAIN AI software-based blockchain, once parallel operation is enabled, it will be the job of the miners to organize Action delivery into independent shards so that they can be evaluated in parallel. The schedule is the output of a miner and will be deterministically executed, but the process for generating the schedule need not be deterministic. This means that miners can utilize parallel algorithms to schedule transactions.

Part of parallel execution means that when a script generates a new Action it does not get delivered immediately, instead it is scheduled to be delivered in the next cycle. The reason it cannot be delivered immediately is because the receiver may be actively modifying its own state in another shard.


## Minimizing Communication Latency

Latency is the time it takes for one account to send an Action to another account and then receive a response. The goal is to enable two accounts to exchange Actions back and forth within a single block without having to wait 0.5 seconds between each Action. To enable this, the BASIC-CHAIN software divides each block into cycles. Each cycle is divided into shards and each shard contains a list of transactions. Each transaction contains a set of Actions to be delivered. This structure can be visualized as a tree where alternating layers are processed sequentially and in parallel.

      Block

        Region

          Cycles (sequential)

            Shards (parallel)

              Transactions (sequential)

                Actions (sequential)

                  Receiver and Notified Accounts (parallel)

Transactions generated in one cycle can be delivered in any subsequent cycle or block. miners will keep adding cycles to a block until the maximum wall clock time has passed or there are no new generated transactions to deliver.

It is possible to use static analysis of a block to verify that within a given cycle no two shards contain transactions that modify the same account. So long as that invariant is maintained a block can be processed by running all shards in parallel.

## Read-Only Action Handlers

Some accounts may be able to process an Action on a pass/fail basis without modifying their internal state. If this is the case, then these handlers can be executed in parallel so long as only read-only Action handlers for a particular account are included in one or more shards within a particular cycle.

## Atomic Transactions with Multiple Accounts

Sometimes it is desirable to ensure that Actions are delivered to and accepted by multiple accounts atomically. In this case both Actions are placed in one transaction and both accounts will be assigned the same shard and the Actions applied sequentially.

## Partial Evaluation of Blockchain State

Scaling blockchain technology necessitates that components are modular. Everyone should not have to run everything, especially if they only need to use a small subset of the applications.

An exchange application developer runs full nodes for the purpose of displaying the exchange state to its users. This exchange application has no need for the state associated with social media applications. BASIC-CHAIN software allows any full node to pick any subset of applications to run. Actions delivered to other applications are safely ignored if your application never depends upon the state of another contract.


## Subjective Best Effort Scheduling

The BASIC-CHAIN software cannot obligate miners to deliver any Action to any other account. Each miner makes their own subjective measurement of the computational complexity and time required to process a transaction. This applies whether a transaction is generated by a user or automatically by a smart contract.

On a launched blockchain adopting the BASIC-CHAIN software, at a network level all transactions are billed a computational bandwidth cost based on the number of WASM instructions executed. However, each individual miner using the software may calculate resource usage using their own algorithm and measurements. When a miner concludes that a transaction or account has consumed a disproportionate amount of the computational capacity they simply reject the transaction when producing their own block; however, they will still process the transaction if other block producers consider it valid.

In general, so long as even 1 miner considers a transaction as valid and under the resource usage limits then all other miners will also accept it, but it may take up to 1 to 10 minutes for the transaction to find that miner.

In some cases, a miner may create a block that includes transactions that are an order of magnitude outside of acceptable ranges. In this case the next miner may opt to reject the block and the tie will be broken by the third miner. This is no different than what would happen if a large block caused network propagation delays.

This subjective evaluation of computational cost frees the blockchain from having to precisely and deterministically measure how long something takes to run. With this design there is no need to precisely count instructions which dramatically increases opportunities for optimization without breaking consensus.

## Deferred Transactions

BASIC-CHAIN Software supports deferred transactions that are scheduled to execute in the future. This enables computation to move to different shards and/or the creation of long-running processes that continuously schedule a continuance transaction.

## Context Free Actions

A Context Free Action involves computations that depend only on transaction data, but not upon the blockchain state. Signature verification, for example, is a computation that requires only the transaction data and a signature to determine the public key that signed the transaction. This is one of the most expensive individual computations a blockchain must perform, but because this computation is context free it can be performed in parallel.

Context Free Actions are like other user Actions, except they lack access to the blockchain state to perform validation. Not only does this enable BASIC-CHAIN to process all Context Free Actions such as signature verification in parallel, but more importantly, this enables generalized signature verification.

With support for Context Free Actions, scalability techniques such as Sharding, Raiden, Plasma, State Channels, and others become much more parallelizable and practical. This development enables efficient inter-blockchain communication and potentially unlimited scalability.

# Token Model and Resource Usage

All blockchains are resource constrained and require a system to prevent abuse. With a blockchain that uses BASIC-CHAIN software, there are three broad classes of resources that are consumed by applications:

1. Bandwidth and Log Storage (Disk);
2. Computation and Computational Backlog (CPU); and
3. State Storage (RAM).

Bandwidth and computation have two components, instantaneous usage and long-term usage. A blockchain maintains a log of all Actions and this log is ultimately stored and downloaded by all full nodes. With the log of Actions, it is possible to reconstruct the state of all applications.

The computational debt is calculations that must be performed to regenerate state from the Action log. If the computational debt grows too large then, it becomes necessary to take snapshots of the blockchain's state and discard the blockchain's history. If computational debt grows too quickly then it may take 6 months to replay 1 year worth of transactions. It is critical, therefore, that the computational debt be carefully managed.

Blockchain state storage is information that is accessible from application logic. It includes information such as order books and account balances. If the state is never read by the application, then it should not be stored. For example, blog post content and comments are not read by application logic, so they should not be stored in the blockchain's state. Meanwhile the existence of a post/comment, the number of votes, and other properties do get stored as part of the blockchain's state.

miners publish their available capacity for bandwidth, computation, and state. The BASIC-CHAIN software allows each account to consume a percentage of the available capacity proportional to the amount of tokens held in a 3-day staking contract. For example, if a blockchain based on the BASIC-CHAIN software is launched and if an account holds 1% of the total tokens distributable pursuant to that blockchain, then that account has the potential to utilize 1% of the state storage capacity.

Adopting the BASIC-CHAIN software on a launched blockchain means bandwidth and computational capacity are allocated on a fractional reserve basis because they are transient (unused capacity cannot be saved for future use). The algorithm used by BASIC-CHAIN software is similar to the algorithm used by Steem and EOS to rate-limit bandwidth usage.

## Objective and Subjective Measurements

As discussed earlier, instrumenting computational usage has a significant impact on performance and optimization; therefore, all resource usage constraints are ultimately subjective, and enforcement is done by miners according to their individual algorithms and estimates. These would typically be implemented by a miner via the writing of a custom plugin.

That said, there are certain things that are trivial to measure objectively. The number of Actions delivered, and the size of the data stored in the internal database are cheap to measure objectively. The BASIC-CHAIN software enables miners to apply the same algorithm over these objective measures but may choose to apply stricter subjective algorithms over subjective measurements.

## Receiver Pays

Traditionally, it is the business that pays for office space, computational power, and other costs required to run the business. The customer buys specific products from the business and the revenue from those product sales is used to cover the business costs of operation. Similarly, no website obligates its visitors to make micropayments for visiting its website to cover hosting costs. Therefore, decentralized applications should not force its customers to pay the blockchain directly for the use of the blockchain.

A launched blockchain that uses the BASIC-CHAIN software does not require its users to pay the blockchain directly for its use and therefore does not constrain or prevent a business from determining its own monetization strategy for its products.

While it is true that the receiver can pay, BASIC-CHAIN enables the sender to pay for bandwidth, computation, and storage. This empowers application developers to pick the method that is best for their application. In many cases sender-pays significantly reduces complexity for application developers who do not want to implement their own rationing system. Application developers can delegate bandwidth and computation to their users and then let the “sender pays” model enforce the usage. From the perspective of the end user it is free, but from the perspective of the blockchain it is sender-pays.

## Delegating Capacity

A holder of tokens on a blockchain launched adopting the BASIC-CHAIN software who may not have an immediate need to consume all or part of the available bandwidth, can delegate or rent such unconsumed bandwidth to others; the miners running BAIC-CHAIN software on such blockchain will recognize this delegation of capacity and allocate bandwidth accordingly.

## Separating Transaction costs from Token Value

One of the major benefits of the BASIC-CHAIN software is that the amount of bandwidth available to an application is entirely independent of any token price. If an application owner holds a relevant number of tokens on a blockchain adopting BASIC-CHAIN software, then the application can run indefinitely within a fixed state and bandwidth usage. In such case, developers and users are unaffected from any price volatility in the token market and therefore not reliant on a price feed. In other words, a blockchain that adopts the BASIC-CHAIN software enables miners to naturally increase bandwidth, computation, and storage available per token independent of the token's value.

A blockchain using BASIC-CHAIN software also awards miners tokens every time they produce a block. The value of the tokens will impact the amount of bandwidth, storage, and computation a producer can afford to purchase; this model naturally leverages rising token values to increase network performance.

## State Storage Costs

While bandwidth and computation can be delegated, storage of application state will require an application developer to hold tokens until that state is deleted. If state is never deleted, then the tokens are effectively removed from circulation.

## Block Rewards

A blockchain that adopts the BASIC-CHAIN software will award new tokens to a miner every time a block is produced. In these circumstances, the number of tokens created is determined by the median of the desired pay published by all miners. The BASIC-CHAIN software may be configured to enforce a cap on miner awards such that the total annual increase in token supply does not exceed 5%.

## Worker Proposal System

Pursuant to a blockchain based on the BASIC-CHAIN software, token holders can elect a number of Worker Proposals designed to benefit the community. The winning proposals will receive tokens of up to a configured percent of the token inflation. These proposals will receive tokens proportional to the votes each application has received from token holders, up to the amount they request for performing their work. The elected proposals can be replaced by newly elected proposals by token holders.


# Governance

Governance is the process by which people in a community:

1. Reach consensus on subjective matters of collective action that cannot be captured entirely by software algorithms;
2. Carry out the decisions they reach; and
3. Alter the governance rules themselves via Constitutional amendments. 

A BASIC-CHAIN software-based blockchain implements a governance process that efficiently directs the existing influence of miners. Absent a defined governance process, prior blockchains relied ad hoc, informal, and often controversial governance processes that result in unpredictable outcomes.

A blockchain based on the BASIC-CHAIN software recognizes that power originates with the token holders who delegate their Token power to staking. The miners are given limited and checked authority to freeze accounts, update defective applications, and propose hard forking changes to the underlying protocol.

Before any change can be made to the blockchain the miners must approve it. If the miners refuse to make changes desired by the community then they can be voted out. If the miners make changes without permission of the community then all other non-miner full-node validators (exchanges, etc) will reject the change.

## Freezing Accounts

Sometimes a smart contact behaves in an aberrant or unpredictable manner and fails to perform as intended; other times an application or account may discover an exploit that enables it to consume an unreasonable amount of resources. When such issues inevitably occur, the miners have the power to rectify such situations.

The miners on all blockchains have the power to select which transactions are included in blocks which gives them the ability to freeze accounts. A blockchain using EOS.IO software formalizes this authority by subjecting the process of freezing an account to a 15/21 vote of active producers. If the producers abuse the power they can be voted out and an account will be unfrozen.

## Changing Account Code

When all else fails and an "unstoppable application" acts in an unpredictable manner, a blockchain using EOS.IO software allows the block producers to replace the account's code without hard forking the entire blockchain. Similar to the process of freezing an account, this replacement of the code requires a 15/21 vote of elected block producers.

## Constitution

The EOS.IO software enables blockchains to establish a peer-to-peer terms of service agreement or a binding contract among those users who sign it, referred to as a "constitution". The content of this constitution defines obligations among the users which cannot be entirely enforced by code and facilitates dispute resolution by establishing jurisdiction and choice of law along with other mutually accepted rules. Every transaction broadcast on the network must incorporate the hash of the constitution as part of the signature and thereby explicitly binds the signer to the contract.

The constitution also defines the human-readable intent of the source code protocol. This intent is used to identify the difference between a bug and a feature when errors occur and guides the community on what fixes are proper or improper.
