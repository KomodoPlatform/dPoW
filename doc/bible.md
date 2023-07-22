# Notary Node Bible v1.2

<b>Introduction:</b> This is the Komodo Platform Notary Node Bible, a compendium with essential information, instructions, rules, policies, election procedures for the Komodo Notary Node network, links to other important documents, and more. This iteration of the NN bible comes into effect at the start of NN Season 7. Please read carefully.

#


### Table of Contents

1. [What is a Notary Node?](#what-is-a-notary-node)
2. [How to become a Notary Node operator](#how-to-become-a-notary-node-operator)
3. [The Notary Node election process](#the-notary-node-election-process)
4. [Responsibilities of a NN](#responsibilities-rights-and-duties-of-a-notary-node-operator)
5. [Notary Node regions](#notary-node-regions)
6. [Guidelines, general information and policies](#guidelines-general-information-and-policies)
7. [dPoW Inprovement Proposals](#dpow-improvement-proposals)
8. [Code of Conduct](#code-of-conduct)


#


## What is a Notary Node?

It’s important for those new to the Komodo ecosystem to understand what exactly Notary Nodes do.
 
Notary Nodes (“NNs”) perform cross-chain notarizations. They simply take a block hash— a string of data that acts as a fingerprint for a specific block in a blockchain— from one blockchain and write it onto the ledger of a different blockchain.
 
Let’s get a bit more specific. A typical block hash looks something like this:
 
0489640207f8c343a56a10e45d987516059ea82a3c6859a771b3a9cf94f5c3bb
 
It’s a 64-character alphanumeric code that identifies a particular block in a blockchain. Since each block is connected to the one that directly preceded it, a block hash can be seen as a unique identifier for the whole chain. The block hash above belongs to block 1,250,000 in the KMD blockchain.
 
Komodo’s Notary Nodes take block hashes like the one above and write them onto different blockchains. This is accomplished with the OP_RETURN command. The OP_RETURN command is a special function that allows a small amount of data to be written onto a blockchain’s ledger when a transaction is executed.
 
Notary nodes don’t actually need to transfer funds when they execute a notarization transaction. Instead, they execute an “empty transaction,” meaning that they pay the blockchain’s transaction fee but don’t actually move any coins. This fee is paid for the privilege of storing data on that blockchain’s ledger.
 
Komodo’s globally distributed network of 64 Notary Nodes carry out these cross-chain  notarizations approximately every ten minutes, every hour of every day, 365 days a year. This process is essential for Komodo’s delayed proof of work security mechanism, Komodo’s Blockchain Security Service, and Komodo’s Multi-Chain Syncing scalability features.
 
In exchange for performing these duties, Notary Node Operators are rewarded with the ability to mine one block with an easy difficulty level roughly every 90 minutes. This allows each Notary Node to mine around 16 or 17 blocks per day on average. As KMD block rewards are 3 KMD per block, this adds up to about 50 KMD per day, or around 1500 KMD per month.
 
Finally, it’s important to emphasize some of the things that Notary Nodes cannot do.
 
- Notary Nodes are not masternodes. The mining rewards offered in exchange for performing Notary Node duties should not be viewed as passive income. Operators should be on standby at all times to swiftly react to update announcements to maintain the security of the network, and failing to do so may result being disqualified from running in future elections.
- Notary Nodes cannot withhold or censor transactions or blocks for any blockchain.
- Notary Nodes cannot mine blocks with an easy difficulty on any chain except the Komodo blockchain.
- Notary Nodes cannot solely determine the validity of a block; an entire decentralized network must come to a consensus before any transactions or blocks are verified.

Notary Nodes simply take publicly-available data that has been established by a blockchain’s network (a block hash) and save it onto the ledger of a different blockchain. This is accomplished by executing an empty transaction, which any ordinary user can do, though Notary Nodes dPoW’s “Iguana” software to coordinate these transactions.

Where consensus is reached by 13 of the 64 Notary Nodes, this results in a transaction such as https://litecoinblockexplorer.net/tx/1bf1a710f6f9a37a91b25a4200efca701506d5133f273fe3926dae317f41a75c with 13 notary node addresses as inputs to the transaction, and sent to a notarisation address as output, along with the OP_RETURN which can be viewed as an output in the transaction’s raw data. 

In the raw data of the transaction above, we can see the OP_RETURN string as being `82546a4e6860681046b972e4d64ee2314f9280bd2192bc059e3c57c7f8326f0dd06f24004b4d4400`

This can in turn be [decoded](http://stats.kmd.io/tools/decode_opret/?OP_RETURN=82546a4e6860681046b972e4d64ee2314f9280bd2192bc059e3c57c7f8326f0dd06f24004b4d4400), resulting in the following information:

Notarised Chain: KMD

Notarised Block: 2387920

Notarised Blockhash: 0d6f32f8c7573c9e05bc9221bd80924f31e24ed6e472b946106860684e6a5482
 
Reviewing the Notarised Blockhash on the Notarised Chain’s explorer yields - https://komodod.com/b/0d6f32f8c7573c9e05bc9221bd80924f31e24ed6e472b946106860684e6a5482

While the notarization process is critical to the security, blockchain interoperability, and scalability of the Komodo ecosystem, Notary Nodes don’t have any special powers over any blockchain. It is a fully decentralized mechanism for cross-chain notarizations.

<br>


## How to become a Notary Node Operator?

Anyone with the required hardware and technical knowledge can become a Notary Node Operator. Please note that dPoW currently only operates on Linux, so an advanced understanding of Linux is implicitly required.
 
<b>The hardware requirements for the main NN server are as follows:</b>
 
- OS: Ubuntu 18.x or Debian 10.x is recommended.  
- CPU: A High-Performance CPU (e.g. Xeon, i7/i9, Ryzen, EPYC, etc.)
- RAM: 64 GB or more
- Disk: 1 TB SSD or greater
- Bandwidth: 100 Mbps or higher

<b>The hardware requirements for the 3P NN server are as follows:</b>

- OS: Ubuntu 18.x or Debian 10.x is recommended.
- CPU: A High-Performance CPU (e.g. Xeon, i7/i9, Ryzen, EPYC, etc.)
- RAM: 32 GB or more
- Disk: 500 GB SSD or greater
- Bandwidth: 100 Mbps or higher

*The server should be bare metal, housed in a Tier 3 datacenter or better. Cloud instances or home connections are not sufficient to ensure bandwidth and uptime.*

Apart from these hardware specifications and the technical know-how, there are no requirements to become a Notary Node Operator. 
 
Candidates do not need to own a single KMD coin to run.  In fact, as pointed out in this article by veteran Komodo team member Satinder Grewal, candidates don’t need to be a current member of the KMD community or know anything about the inner workings of Komodo’s technology to become an NN Operator.
 
For more information about becoming a Notary Node Operator, please see this guide.
 
To gain exposure and inform the Komodo community about one’s candidacy, as well as the motivations for that candidacy, it’s essential to submit a written proposal to the Komodo community. 
 
<b>If you plan to run in an upcoming election, you need to submit your proposal to the Notary Node repository on [Github](https://github.com/KomodoPlatform/NotaryNodes/tree/master/season6/candidates) prior to the proposal deadline for the next election. </b>
 
At a minimum, every candidate Proposal must include:
- The region in which they are running and post the address to which KMD holders may send VOTE tokens to support their candidacy.
- Contact details (such as Discord, Keybase, Telegram and/or  Email) for ensuring open communications about what to do after the election.
- If running as part of a team or on behalf of a project / company, additional details about the project / company and other team members.

Proposals failing to meet these requirements before the deadline may be rejected. Participation in the pre-election Testnet is highly recommended for any candidates who have not previously run a Notary Node.

Generally the Komodo community elects Notary Node Operators who are committed to the development of the ecosystem, as demonstrated by making contributions to code or community projects. If your primary motivation is personal financial gain, you may find it difficult to garner support, even if you have proven your technical skills during the pre-election Testnet.

Conversely, even if you are an ardent supporter of the Komodo ecosystem, you may fail to win a seat if your technical skills are unproven. A balance of both attributes — dedication to the Komodo ecosystem and strong technical abilities — is the ideal combination.

For more information about the pre-election Testnet check out the [testnet README](https://github.com/KomodoPlatform/dPoW/blob/2022-testnet/README.md)
<br>


## The Notary Node Election Process
 
There are four Notary Node regions: Europe (EU), Asia-Russia (AR), North America (NA), and the Southern Hemisphere (SH). Each region contains 14 notary nodes, boosting the physical distribution and security of Komodo’s Notary Node network. 

11 of the nodes in each region are open for election candidates to win, with 3 reserved for the prior season’s top performing nodes who are automatically re-elected.

An additional 8 nodes are reserved as “Dev nodes”, and assigned by the Komodo Team to proven operators for use in various tasks relating to testing and development.
 
Winning Notary Node operators must run their node in the region declared in their proposal, and face disqualification if discovered to be non compliant, with their NN spot being assigned to the next candidate in line in the election results. This keeps things fair, as different geographic locations offer Internet connections at varying costs and speeds.


| Region     | Season 6 Winners | VOTE2023 Winners  | Total  |
|------------|------------------|-------------------|--------|
| AR         | 3                | 11                | 14     |
| EU         | 3                | 11                | 14     |
| NA         | 3                | 11                | 14     |
| SH         | 3                | 11                | 14     |
| Dev        | -                | -                 | 8      |
| **Total**  |                  |                   | **64** |


New candidates are eligible to submit a candidacy for a single notary node in any of the four regions in their first election. Participation in the pre-season Testnet is <b>highly recommended</b> to learn the basics and demonstrate capability.

Notary nodes achieving a regional top 3 ranking at the ranking snapshot date are automatically re-elected to operate that node in the next season. 

Notary nodes achieving a regional top 5 ranking are eligible to submit a candidacy for an additional notary node for each region they held a top 5 position in at the ranking snapshot date.

Notary nodes who are not in their regional top 5 at the end of the season can reapply for a single node for each of the region(s) they served in during the previous season.

Notary Node veterans who have served in at least two prior seasons are eligible to apply for an additional node (veteran benefit).


| Category           | Auto re-elected  | Proposal eligibility   | Max nodes  |
|--------------------|------------------|------------------------|------------|
| Regional Top 3     | 1 per region     | 2 per top 5 node       | 6          |
| Regional Top 5     | 0                | 2 per top 5 node       | 6          |
| Other S6 Notaries  | 0                | 1 per prior region + 1 | 5          |
| Returning veterans | 0                | 2                      | 2          |
| New Candidates     | 0                | 1                      | 1          |


<b>No notary can hold more than 2 nodes in a single region, or more than 6 nodes in total.</b>

The Komodo Notary Node Elections are stake weighted, meaning that those who hold more KMD have more voting power in the election. The process works as follows.
 
A special voting token — let’s call it VOTE — will be airdropped to KMD holders at a 1:1 ratio. If you have 1000 KMD, you will receive 1000 VOTE tokens.

The current supply of KMD is around 125 Million, so roughly 125 Million VOTE tokens will be airdropped.
 
It’s important to note that you must hold you private keys in order to receive your VOTE tokens. If you hold your KMD on a centralized exchange, then you do not hold your private keys and you will not receive any VOTE tokens.

CEX (wallets) are excluded from voting and users are advised to vote only from wallets whose private keys they fully control. VOTE token transactions from CEX wallets are not counted.
 
Once you’ve received your VOTE tokens, you may cast your ballot by sending them to the candidate(s) of your choice. All candidates will publicly post an address and the community votes by sending the tokens to the candidate(s) they wish to see elected.
 
The only rule for voting is that any redistribution or sale of VOTE tokens is strictly prohibited. Anyone caught selling VOTE tokens will be disqualified from participating in the election.

It is also strictly prohibited to offer NN revenue shares (mining revenue share) to voters.
 
Apart from that, community members may vote for any candidates in any region. VOTE tokens can be sent in any amount so there is no requirement to cast votes in any set percentages for any number of candidates in any region.
 
For instance, if you want to send 100% of your VOTE tokens to a single candidate, you may do so. If you want to send 20% of your votes to five different candidates in a single region, you may do that, too. If you want to send an equal 25% of your votes to one candidate in each of the four regions, that’s also an option. There are no rules dictating how you cast your ballot.


# Timeline

Each year around the start of April, a `Ranking Snapshot` will be taken and in the week following, Notary Node scores are validated before an official announcement is made to name the auto-elected nodes, and those eligible for expanding into additional spots in the coming election. 

Around the same time, a snapshot of the KMD chain is done, to determine the allocation of VOTE tokens for each address, and then airdropped to holders after the previous season’s winners are announced. 

While the above is underway, candidate proposals can be submitted via a Pull Request (PR) to the Notary Nodes repository on Github (some modifications may be required based on Ranking announcement results). 

The voting period typically runs for around two weeks, with the time and date of the ballots closing being announced in advance. The election officially ends with the first notarised block confirmed after this date / time, with all votes within this block and those prior included in the count.

The voting data is then validated, with any votes originating from a CEX wallet or being cast to a disqualified candidate being excluded, before an official announcement of winners is released.

It is highly recommended that each community member read through the proposals of all the candidates before casting their vote. The proposals contain important information about how each candidate intends to help the Komodo ecosystem. All candidates' proposals, along with other useful dates and information, will be posted within the Komodo Notary Node Election GitHub repository.

Exact dates and times for each of the events above will be posted within this document and announced before the start of the annual notary node election.

## Responsibilities, Rights and Duties of a Notary Node Operator

Operating a Notary Node comes with various responsibilities but also grants you certain privileges for securing the Komodo network with dPoW. Operators who fail to adequately perform the required duties will face disqualification and loss of their node. Notary Nodes are responsible for protecting over a billion (fiat) dollars in assets, and must remain vigilant and respond quickly to any update announcements posted in Discord and the dPoW repository, along with ensuring that their node is secure and performing as expected at all times.


### NN Duties:

- <b>i.</b> Keep your Notary Node up to date (daily maintenance, update and upgrade check) and secured (according to the industry's best practices).
- <b>ii.</b> Notarize all active dPoW assets and participate in all expected notarization rounds without any interruptions (this will be checked daily). Some allowances are made for  brief downtimes to allow required maintainence. 
- <b>iii.</b> Mine Komodo blocks with your NN pubkey (minimum 15 blocks a day on average).
- <b>iv.</b> Subscribe to [the dPoW repository](https://github.com/KomodoPlatform/dpow) and react in a timely manner (<24h) to notifications and update announcements (do not run for a NN position unless you can guarantee daily maintenance).
- <b>v.</b> Help other NN Operators in need and keep an eye on your geo-regional statistics. The most reliable regions may receive additional benefits and bounties. 
- <b>vi.</b> Report any violation that you notice ASAP to the Komodo team through security@komodoplatform.com.
- <b>vii.</b> Participate in discussions and publish your improvement proposals on [the dPoW repository](https://github.com/KomodoPlatform/dpow). (exempt from enforcement)
- <b>viii.</b> Physically separate your main and 3rd party NN operations by using different servers.
- <b>ix.</b> Use ONLY the original dPoW and Komodo Core codebases. Any core or protocol modification, non-public optimization, or similar code changes, will lead to immediate loss of the spot and disqualification.
- <b>x.</b> Operate your NN in the assigned region. Using hosting providers with DCs in other regions and obfuscating this by using IPs from other regions will lead to immediate disqualification. 
- <b>xi.</b> Selling a NN spot is prohibited. This rule applies to all forms of disposition (giveaway, renting,...).
- <b>xii.</b> Notarization funds, deposited on your NN keys by the Komodo team, are reserved for dPoW operations - it is strictly prohibited to transfer these funds or to use these for anything other than notarizations. At the end of the NN season or if you lose your spot, all NN funds must be returned to the Komodo team. Notaries are responsible for ensuring sufficient KMD is sent from main node to third party node for use in notarisation (funding for other chains will be provided by the Komodo Team).
- <b>xiii.</b> Maintain respectful and civil communications with fellow Notary Node operators, and members of the Komodo Community.

**Note:** _In some circumstances, non-DEV nodes could be assigned to participate in developer or security related tasks. Selection of these nodes will be based on operator experience, skillset and task specific requirements. With respect to ensuring dPoW remains operational, there is a limit of 4 nodes eligible for this assignment. Participation is voluntary. Operators who consent will receive no benefit to their score for their involvement, and accept the risk of losing potential end of season top 5 rank benefits if their score suffers as a result of participating._


### NN Rights:

- <b>i.</b> Mining KMD blocks with a minimum diff (guaranteed easy mining revenue).
- <b>ii.</b> Making dPoW and NN improvement proposals and requesting votes/polls for these proposals.
- <b>iii.</b> Having the opportunity to achieve automatic re-election upon reaching a Top 3 regional ranking, or the chance at expansion into additional nodes if ranked 4th or 5th.
- <b>iv.</b> Accessing the private NN Discord community chat, as long as a mature and respectful basis of discussion is given. 
- <b>v.</b> Having the chance to become the NN guru for your region if you are ranked #1 NN in that region for a minimum of 1 full month. 


## Notary Node regions

- Green: NA
- Yellow: EU
- Red: SH
- Blue: AR

![NN Regions](https://github.com/komodoplatform/dpow/blob/master/doc/img/NN_regions.jpeg)


## Guidelines, General Information and Policies 

### Important Dates for Season 7:
| Event | Date | Timestamp |
| --- | --- | --- |
| KMD snapshot for VOTE2023                  | 7th April 2023                 | 1680911999  |
| Season 6 scoring ends                      | 7th April 2023, 23:59:59 UTC   | 1680911999  |
| Season 6 Auto re-elected winners announced | 14th April 2023                | 1681516799  |
| VOTE2023 airdrop                           | 14th April 2023                | 1681516799  |
| Season 7 Candidate proposals recieved      | 1st-21st April 2023            | 1682121599  |
| Season 7 Election start                    | 14th April 2023                | 1681516799  |
| Season 7 Election end                      | 30th April 2023, 23:59:59 UTC* | 1682899199  |
| Season 7 Election Winners announced        | 7th May 2023                   | 1683503999  |
| Komodo deamon Season 7 update released     | 31st May 2023                  | 1685577599  |
| Hardfork / dPoW season 7 start             | 30th June 2023                 | 1688169599  |

* Votes cast in the election are valid until the first notarised block (inclusive) after 30th April 2023, 23:59:59 UTC.



### The Komodo Mining Ecosystem:

The Komodo mining ecosystem is exceptional in that a large part of the mining revenue (~75%) is reserved for the Notary Nodes, as they provide the network with the dPoW service and basically maintain the security of the network and all dPoW notarised chains. Thus the regular PoW miners on the Komodo network are eligible for approximately 25% of the mining revenue. 


### Automatic Re-election:

The top 3 NNs for each region are automatically re-elected. The other 44 public NN spots are claimable through the annual NN elections. 


### Notary Scoring:

To determine relative participation notary scoring, refer to the following:

- KMD -> LTC Notarisation: 0.0325 
- Smartchain -> KMD notarisation: 0.8698/(number of main server chains*, not including KMD/LTC)
- 3rd Party chain -> KMD notarisation: 0.0977/(number of active 3rd party server chains*, not including KMD)
- MM2 Seed Node -> 0.2 per hour uptime with correct version

Notarisation counts to be determined from decoded notarisation transaction OP_RETURN data on KMD block chain.

\* As listed in 
- https://github.com/KomodoPlatform/dPoW/blob/master/README.md
- https://github.com/KomodoPlatform/dPoW/blob/master/doc/scoring_epochs.json

Scoring starts for newly added coins 24hrs after a commit is merged, and ends when a coin removal commit is merged to the master branch (or at the official start/end times of the season for existing coins).

### Leveraging the Notary Node Network to decentralize MM2 seed nodes

Komodo Platform's [AtomicDEX-API](https://github.com/KomodoPlatform/atomicDEX-API) is an open-source atomic-swap protocol for trading seamlessly between essentially any blockchain asset in existence. Seed nodes play an essential part in orderbook propagation and relaying information about peers within the network and the status of swaps in progress.

With the start of the 6th Komodo Notary Node Season, operators will be encouraged to run a seed node on their third party (3P) server to further decentralize the network. This expands the current number of seed nodes from half a dozen to potentially over 60 nodes, distributed geographically across the planet, and maintained by a diverse group of respected people within the Komodo community with great expertise in KMD related technologies and the ability to rapidly deploy updates and assist each other with troubleshooting as required.

Operators with the best metrics in terms of uptime and responsiveness to updates will also be rewarded with bonus points towards their Season 6 score, and the chance to win automatic re-election.

For each hour of uptime with the correct version, Notary Nodes will receive 0.2 points to their season score.

Simple scripts to assist operators in setting up their seed node and keeping it up to date whenever update announcements are available at https://github.com/smk762/nn_mm2_seed


### Developer Nodes:

Eight Nodes are reserved for the Komodo team for mining and experimental, debugging, or research operations, which include the usage of custom and experimental core code. In some circumstances, non-DEV nodes could be assigned to participate in developer or security related tasks. Selection of these nodes will be based on operator experience, skillset and task specific requirements. With respect to ensuring dPoW remains operational, there is a limit of 4 nodes eligible for this assignment. Participation is voluntary. Operators who consent will receive no benefit to their score for their involvement, and accept the risk of losing potential end of season top 5 rank benefits if their score suffers as a result of participating.


### Hunting Unclaimed Rewards:

The consensus rules allow every network participant to hunt the so-called “unclaimed reward blocks” which contain additional mining-rewards.


### Mining Komodo Blocks with Your NN Pubkey:

In the event a NN opts to hunt, as above, that NN must find some way to contribute block production to the network similar to the result of "traditional NN mining". This contribution shall be no less than 75% of the blocks produced by the region's leading block producing NN and in any event not below 15 blocks per day on average over the course of a calendar month. The contribution may be through means of only hunting part time, employing "external" hashrate full-time, or some combination of the two. This contribution shall <b>not</b> include mining several blocks in a short time with "external" hashrate and then abandoning the chain for a time, such an action does not produce a "similar result".


### NN Gurus:

During the removal of the “NN master” role, the decision was made to create a new “NN guru” role, which does not have any authoritative power.

The NN gurus are the top NN operators of each region (ranked #1). These NN operators get the opportunity to be the NN guru if they hold rank 1 for at least one month. There is a tolerance timeframe of  1 month in which a NN guru could fall off his rank and still remain NN guru with the chance to climb back up. After a full month has passed with a new 1 rank, the NN guru role will be reassigned. 

NN gurus have additional duties and rights. They are “responsible” for their geo-region and should do their best to motivate, support, and push “weak” NN Operators to boost their region’s notarization statistics. NN gurus also support the Komodo team during the elections, initial setups, etc. In exchange the Komodo team will assign these NN gurus additional bounties and bonuses.


### NN Arbiter:

A Komodo team-member that is not involved in the NN/dpow operations nor in the NN community will server in the role of a NN Arbiter assigned which will make a final decisions with reference to rule violations, disqualifications and bans on the basis and merits of evidence submitted by NN Gurus and the NN Tribunal. The NN Arbiter will be appointed on an as-needed basis.


### NN Tribunal:

Two Komodo team-members form together alongside two (non-team) NN Gurus to ensure an objective decision finding process in case of unclear situations and controversial debates related to a rule violation. The NN tribunal will be formed on an as-needed basis.


#### The current NN Gurus are:

CHMEX (@CHMEX#0686 on discord): EU region <br>
Shossain (@SHossain#0007 on discord): AR and NA region <br>
Strob (@Strob#3417): SH region <br>


### Rules and Enforcement - historic information for transparency:

In the previous Notary Node seasons, there were no protocolled rules or policies, which lead to certain confusion in the sense of the Latin phrase “nullum crimen, nulla poena sine lege,” which means someone cannot be punished for something that is not prohibited by law. 

We reconsidered this part and decided to author and publish these transparent guidelines which we call the “Notary Node Bible”. The Komodo team also decided that a violation of any of the above [rules](#responsibilities-rights-and-duties-of-a-nn) may result in immediate loss of the NN spot, disqualification from election or other sanctions as deemed appropriate by the NN Arbiter. In the event that a single individual has additional violations in subsequent seasons, it could lead to disqualification from all future elections and seasons. 

A "grace period" at the beginning of each season will apply until September 1st for first time notaries, to allow for adjustment to rules based on the framework established in this document, and to give new notaries time to make mistakes, learn and tweak their servers. During this time, minor infractions may lead to "probationary status" with Gurus and the NN community assisting non-conforming operators achieve stable and productive participation. Major infractions (i.e. grossly negligent or malicious activity) will be subject to harsher penalty up to and including spot-loss / disqualification.

In case of such a spot-loss or disqualification, the next candidate from the election results will be eligible for the spot and the pubkey would be replaced with the next scheduled hardfork update. 


### NN Season

A NN season may not equal 12 months - it will cover mininmum 75%, 3 quarters (9 months) of a year but could also last longer than a year under specific circumstances. 


### Notary Node Setup:

You find all essential infos and setup instructions on [the dPoW repository](https://github.com/KomodoPlatform/dpow)
Operators are also encouraged to ask questions relating to setup and operation in Discord or via direct messaging with NN Gurus.


#### Recommended min hardware setup for main NN: 
 
- OS: Ubuntu 20.x or Debian 11.x is recommended.
- CPU: A High-Performance CPU (e.g. Xeon, i7/i9, Ryzen, EPYC, etc.)
- RAM: 64 GB or more
- Disk: 1 TB SSD or greater
- Bandwidth: 100 Mbps or higher


#### Recommended min hardware setup for 3P NN: 
 
- OS: Ubuntu 20.x or Debian 11.x is recommended.
- CPU: A High-Performance CPU (e.g. Xeon, i7/i9, Ryzen, EPYC, etc.)
- RAM: 32 GB or more
- Disk: 500 GB SSD or greater
- Bandwidth: 100 Mbps or higher


## dPoW Improvement Proposals

The dPoW Improvement Proposals [DIPS](https://github.com/KomodoPlatform/dips/) repository serves as a platform to facilitate discussion, collaboration and the review of proposed changes to dPow and the notary node operations. We believe that having an open and transparent process helps foster good governance and trust between the Komodo community and our development teams.

Any external collaborator pull requests to the dPoW repository should be accompanied by DIP to explain the proposed changes. DIPs can also be submitted to discuss rule changes to the Notary Node bible (this document).

Once a DIP has been submitted:
 - There will be a minimum of 2 weeks for comments regarding a DIP to be given after which it may be closed, or may proceed to a vote in order to ratify or reject the proposal.
 - Upcoming votes will be announced in the #notary-nodes channel on the Komodo Discord server a minimum of 2 weeks prior to the initiation of a vote.
 - The voting period will run for one week, with any past or present notary node eligible to vote.
 - Votes will be validated by the Komodo team, and the results will be announced in the #notary-nodes channel on the Komodo Discord server no later than one week after the voting period ends.
 - Votes are allocated 1:1 for each address used to run a main server notary node, for each season it was in use.
 - Votes are to be cast via a signed message, generated by the address used in a notary's main notary node, for each season in was in use.
 - The vote schedule will be determined by a consensus of current DEV node notaries, with respect to the nature of the proposed changes and the time remaining until a hardfork.
 - Proposals which only attract 20 votes or less will be considered invalid, and the proposal rejected.
 - Votes which attract at least 21 votes, but less than 33 votes will require a 2/3rds majority be considered valid. If this threshold is not achieved, the proposal will be reset and a new vote scheduled.


Signed messages must conform to the following format to be considered valid:

`{NOTARYNAME}_{REGION} S{SEASON_NUM} [supports|rejects] {DIP_NUM}`

For example:
```
$ komodo-cli signmessage RDragoNHdwovvsDLSLMiAEzEArAD3kq6FN "dragonhound_DEV S6 supports DIP0001"
> IDETpoMoWojS/bXCcLdMWyCRas1aL7NRnideIns0ega4HQYwJWjOfIv3hKNfSsZADxT+ZbWM2govNxCFh+esOtI=
```

The vote is then cast in the relevant DIP thread as a comment as below:
```
  Notary: dragonhound_DEV
  Season: S6
  Address: RDragoNHdwovvsDLSLMiAEzEArAD3kq6FN
  Message: "dragonhound_DEV S6 supports DIP0001"
  Signature: IDETpoMoWojS/bXCcLdMWyCRas1aL7NRnideIns0ega4HQYwJWjOfIv3hKNfSsZADxT+ZbWM2govNxCFh+esOtI=
```

It can then be validated with:
```
$ komodo-cli verifymessage RDragoNHdwovvsDLSLMiAEzEArAD3kq6FN "IDETpoMoWojS/bXCcLdMWyCRas1aL7NRnideIns0ega4HQYwJWjOfIv3hKNfSsZADxT+ZbWM2govNxCFh+esOtI=" "dragonhound_DEV S6 supports DIP0001"`
> true
```

## Code of Conduct

Before we get started, here are a few things we expect from you (and that you should expect from others):

Be kind and thoughtful in your conversations around this project. We all come from different backgrounds and projects, which means we likely have different perspectives on "how something is done." Try to listen to others rather than convince them that your way is correct.
As contributors and maintainers of this project, and in the interest of fostering an open and welcoming community, we pledge to respect all people who contribute through reporting issues, posting feature requests, updating documentation, performing dPoW operations as a NN, submitting pull requests or patches, participating in discussions, and other activities.
We are committed to making participation in this project a harassment-free experience for everyone, regardless of level of experience, gender, gender identity and expression, sexual orientation, disability, personal appearance, body size, race, ethnicity, age, religion, or nationality.
Examples of unacceptable behavior by participants include:

* The use of sexualized language or imagery
* Personal attacks
* Trolling or insulting/derogatory comments
* Public or private harassment
* Publishing other's private information, such as physical or electronic addresses, without explicit permission
* Other unethical or unprofessional conduct

Project maintainers have the right and responsibility to remove, edit, or reject comments, posts, commits, code, wiki edits, issues, and other contributions that are not aligned to this Code of Conduct, or to ban temporarily or permanently any contributor for other behaviors that they deem inappropriate, threatening, offensive, or harmful. Note that contributors may be volunteers who do not represent Komodo Platform. They are free to express their own opinions so long as they adhere to these guidelines.

By adopting this Code of Conduct, project maintainers commit themselves to fairly and consistently applying these principles to every aspect of managing this project. Project maintainers who do not follow or enforce the Code of Conduct may be permanently removed from the project team.

This Code of Conduct applies both within project spaces and in public spaces when an individual is representing the project or its community.

Instances of abusive, harassing, or otherwise unacceptable behavior may be reported by contacting a project maintainer (see below). All complaints will be reviewed and investigated and will result in a response that is deemed necessary and appropriate to the circumstances. Maintainers are obligated to maintain confidentiality with regard to the reporter of an incident.

You may send reports to developer@komodoplatform.com. 

If you wish to contact specific maintainers directly, the following have made themselves available for conduct issues:

- smk (smk at komodoplatform.com)
- TonyL (alysakov at komodoplatform.com)
- gcharang (gcharang at komodoplatform.com)
- ca333 (ca333 at komodoplatform.com)

This Code of Conduct is adapted from https://www.contributor-covenant.org/version/1/3/0/ 
https://www.contributor-covenant.org 


### Contact Info:

#### E-mail:

- alysakov@komodoplatform.com
- smk@komodoplatform.com
- alright@komodoplatform.com
- kolo@komodoplatform.com 
- dpow@komodoplatform.com
- ca333@komodoplatform.com


#### Discord:
http://www.komodoplatform.com/discord


#### Github:
https://github.com/komodoplatform 


#### Emergency contact for vuln reports:
security@komodoplatform.com 


Please feel free to provide your feedback, objections and suggestions. 
