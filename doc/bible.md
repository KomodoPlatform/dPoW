# Notary Node Bible v1



<b>Introduction:</b> This is the Komodo Platform Notary Node Bible, a compendium with essential information, instructions, rules, policies, election procedures for the Komodo Notary Node network, links to other important documents, and more. The NN bible comes into effect by the start of NN Season 5, which will be on June 14th, 2021. Election related rules apply for the Season 5 elections, with immediate effect. Please read carefully. 

#

### Table of content

1. [What is a Notary Node?](https://github.com/KomodoPlatform/dPoW/new/dev/doc#what-is-a-notary-node)
2. [How to become a Notary Node operator](#how-to-become-a-notary-node-operator)
3. [The Notary Node election process](#the-notary-node-election-process)
4. [Responsibilities of a NN](#responsibilities-rights-and-duties-of-a-nn)
5. [Notary Node regions](#notary-node-regions)
6. [Guideline, general infos and policies](#guideline-general-infos-and-policies)
7. [Code of Conduct](#code-of-conduct)

#

<br>

## What is a Notary Node?

It’s important for those new to the Komodo ecosystem to understand what exactly Notary Nodes do.
 
Notary Nodes (“NNs”) perform cross-chain notarizations. They simply take a block hash— a string of data that acts as a fingerprint for a specific block in a blockchain— from one blockchain and write it onto the ledger of a different blockchain.
 
Let’s get a bit more specific. A typical block hash looks something like this:
 
0489640207f8c343a56a10e45d987516059ea82a3c6859a771b3a9cf94f5c3bb
 
It’s a 64-character alphanumeric code that identifies a particular block in a blockchain. Since each block is connected to the one that directly preceded it, a block hash can be seen as a unique identifier for the whole chain. The block hash above belongs to block 1,250,000 in the KMD blockchain.
 
Komodo’s Notary Nodes take block hashes like the one above and write them onto different blockchains. This is accomplished with the OP_RETURN command. The OP_RETURN command is a special function that allows a small amount of data to be written onto a blockchain’s ledger when a transaction is executed.
 
Notary nodes don’t actually need to transfer funds when they execute a notarization transaction. Instead, they execute an “empty transaction,” meaning that they pay the blockchain’s transaction fee but don’t actually move any coins. This fee is paid for the privilege of storing data on that blockchain’s ledger.
 
Komodo’s globally distributed network of 64 Notary Nodes carry out these cross-chain notarizations every ten minutes, every hour of every day, 365 days a year. This process is essential for Komodo’s delayed proof of work security mechanism, Komodo’s Blockchain Security Service, and Komodo’s Multi-Chain Syncing scalability features.
 
In exchange for performing these duties, Notary Node Operators are rewarded with the ability to mine one block with an easy difficulty level roughly every 90 minutes. This allows each Notary Node Operator to easily mine 16 or 17 blocks per day. As KMD block rewards are 3 KMD per block, this adds up to about 50 KMD per day, or around 1500 KMD per month.
 
Finally, it’s important to emphasize some of the things that Notary Nodes cannot do.
 
Notary Nodes are not masternodes.
Notary Nodes cannot withhold or censor transactions or blocks for any blockchain.
Notary Nodes cannot mine blocks with an easy difficulty on any chain except the Komodo blockchain.
Notary Nodes cannot solely determine the validity of a block; an entire decentralized network must come to a consensus before any transactions or blocks are verified.
 
Notary Nodes simply take publicly-available data that has been established by a blockchain’s network (a block hash) and save it onto the ledger of a different blockchain. This is accomplished by executing an empty transaction, which any ordinary user can do.  
 
While the notarization process is critical to the security, blockchain interoperability, and scalability of the Komodo ecosystem, Notary Nodes don’t have any special powers over any blockchain. It is a fully decentralized mechanism for cross-chain notarizations.

<br>

## How to become a Notary Node operator?

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


Apart from these hardware specifications and the technical know-how, there are no requirements to become a Notary Node Operator. 
 
Candidates do not need to own a single KMD coin to run.  In fact, as pointed out in this article by veteran Komodo team member Satinder Grewal, candidates don’t need to be a current member of the KMD community or know anything about the inner workings of Komodo’s technology to become an NN Operator.
 
For more information about becoming a Notary Node Operator, please see this guide.
 
To gain exposure and inform the Komodo community about one’s candidacy, as well as the motivations for that candidacy, it’s essential to submit a written proposal to the Komodo community. 
 
<b>If you plan to run in the upcoming election, you have to submit your proposal to the Notary Node repository on [Github](https://github.com/KomodoPlatform/NotaryNodes/tree/master/season5/candidates) before April 17th, 2021. </b>
 
At a minimum, every candidate must announce the region in which they are running and post the address to which KMD holders may send their VOTE tokens. 
 
In general, the Komodo community elects Notary Node Operators who are committed to the development of the ecosystem. If your primary motivation is personal financial gain, you may find it difficult to garner support, even if you have proven your technical skills on Komodo’s test net.

Conversely, even if you are an ardent supporter of the Komodo ecosystem, you may fail to win a seat if your technical skills are unproven. A balance of both attributes — dedication to the Komodo ecosystem and strong technical abilities — is the ideal combination.

For more information on joining the preseason testnet check out the [testnet README](https://github.com/KomodoPlatform/dPoW/blob/2021-testnet/README.md)
<br>

## The Notary Node election process
 
There are four Notary Node regions: Europe (EU), Asia-Russia (AR), North America (NA), and the Southern Hemisphere (SH). Each region contains at least 13 notary nodes, boosting the physical distribution and security of Komodo’s Notary Node network. In 2021, each region will have an even 14 Notary Nodes.
 
Those running for election must declare in which region they intend to operate their Notary Node. If anyone is discovered to be running a node in a region other than the one for which they were elected, this operator will be immediately disqualified and the NN spot gets assigned to the next candidate in the election result list. This keeps things fair, as different geographic locations offer Internet connections at varying costs and speeds.

New candidates are eligible to submit a candidacy for a single notary node in any of the four regions in their first election. Participation in the pre-season testnet is <b>highly recommended</b> to learn the basics and demonstrate capability.

Notary nodes achieving a regional top 3 ranking at the ranking snapshot date are automatically re-elected to operate that node in the next season. 

Notary nodes achieving a regional top 5 ranking are eligible to submit a candidacy for an additional notary node for each region they held a top 5 position in at the ranking snapshot date.

Notary nodes who are not in their regional top 5 at the end of the season can reapply for a single node for each of the region(s) they served in during the previous season.

<b>No notary can hold more than 2 nodes in a single region, or more than 6 nodes in total.</b>

The Komodo Notary Node Elections are stake weighted, meaning that those who hold more KMD have more voting power in the election. The process works as follows.
 
A special voting token — let’s call it VOTE2021 — will be airdropped to KMD holders at a 1:1 ratio. If you have 1000 KMD, you will receive 1000 VOTE2021 tokens.

A snapshot for the airdrop will be taken at the same time as the Notary Node ranking snapshot on April 2nd, 2021. Auto-elected Notary Nodes (top 3 in each region) will be announced and VOTE2021 tokens will be airdroped on April 9th, 2021.

The current supply of KMD is around 125 Million, so roughly 125 Million VOTE2021 tokens will be airdropped.
 
It’s important to note that you must hold you private keys in order to receive your VOTE2021 tokens. If you hold your KMD on a centralized exchange, then you do not hold your private keys and you will not receive any VOTE2021 tokens.
 
Once you’ve received your VOTE2021 tokens, you may cast your ballot by sending them to the candidate(s) of your choice. All candidates will publicly post an address and the community votes by sending the tokens to the candidate(s) they wish to see elected.
 
The only rule for voting is that any redistribution or sale of VOTE2021 tokens is strictly prohibited. Anyone caught selling VOTE2021 tokens will be disqualified from participating in the election.

It is also strictly prohibited to offer NN revenue shares (mining revenue share) to voters.

CEX (wallets) are excluded from voting and users are advised to vote only from wallets whose private keys they fully control. VOTE2021 token transactions from CEX wallets are not counted.
 
Apart from that, community members may vote for any candidates in any region. VOTE2021 tokens can be sent in any amount so there is no requirement to cast votes in any set percentages for any number of candidates in any region.
 
For instance, if you want to send 100% of your VOTE2021 tokens to a single candidate, you may do so. If you want to send 20% of your votes to five different candidates in a single region, you may do that, too. If you want to send an equal 25% of your votes to one candidate in each of the four regions, that’s also an option. There are no rules dictating how you cast your ballot.
 
Voting will be open for around two weeks, until April 23rd, 2021. It is highly recommended that each community member read through the proposals of all the candidates before casting their vote. The proposals contain important information about how each candidate intends to help the Komodo ecosystem.
 
All of the candidates' proposals, along with other useful information, will be posted on this new Komodo Notary Node Election GitHub repo.

<b>The top 12 NNs who will be auto-elected will be announced on April 9th. 44 Notary Node spots are available in the 2021 election. Starting with season 4 the automatic re-elections were reduced to 3 spots per region.

The elections start on April 9th with the airdrop of the VOTE2021 tokens and end on April 23rd, 2021. The Komodo Core update is planned for April 30th, 2021 and the hardfork activation for June 14th, 2021. </b>


<br>

## Responsibilities (“rights and duties”) of a NN

Operating a Notary Node comes with various responsibilities but also grants you certain privileges for securing the Komodo network with dPoW.


### NN Duties:

- <b>i.</b> Keep your Notary Node up to date (daily maintenance, update and upgrade check) and secured (according to the industry's best practices).
- <b>ii.</b> Notarize all active dPoW assets and participating in all expected notarization rounds without any interruptions (this will be checked daily). 
- <b>iii.</b> Mine Komodo blocks with your NN pubkey.
- <b>iv.</b> Subscribe to https://github.com/KomodoPlatform/dpow and react in a timely manner (<24h) to notifications and update announcements (do not run for a NN position unless you can guarantee daily maintenance).
- <b>v.</b> Help other NN Operators in need and keep an eye on your geo-regional statistics. The most reliable regions will receive additional benefits and bounties. 
- <b>vi.</b> Report any violation that you notice ASAP to the Komodo team through security@komodoplatform.com.
- <b>vii.</b> Participate in discussions and publish your improvement proposals on https://github.com/KomodoPlatform/dpow. (exempt from enforcement)
- <b>viii.</b> Physically separate your main and 3rd party NN operations by using different servers.
- <b>ix.</b> Use ONLY the original dPoW and Komodo Core codebases. Any core or protocol modification, non-public optimization, or similar code changes, will lead to immediate loss of the spot and disqualification.
- <b>x.</b> Operate your NN in the assigned region. Using hosting providers with DCs in other regions and obfuscating this by using IPs from other regions will lead to immediate disqualification. 
- <b>xi.</b> Selling a NN spot is prohibited. This rule applies to all forms of disposition (giveaway, renting,...).
- <b>xii.</b> Notarization funds, deposited on your NN keys by the Komodo team, are reserved for dPoW operations - it is strictly prohibited to transfer this funds or to use them for anything other then notarizations. At the end of the NN season or if you lose your spot, all NN funds must be returned to the Komodo team. Notaries are responsible for ensuring sufficient KMD is sent from main node to third party node for use in notarisation (funding for other chains will be provided by the Komodo Team).

### NN Rights:

- <b>i.</b> Mining KMD blocks with a minimum diff (= guaranteed mining revenue).
- <b>ii.</b> Making dPoW and NN improvement proposals and requesting votes/polls for these proposals.
- <b>iii.</b> Having the opportunity to get automatically re-elected upon reaching a specific ranking.
- <b>iv.</b> Accessing the private NN Discord community chat, as long as a mature and respectful basis of discussion is given. 
- <b>v.</b> Having the chance to become the NN guru for your region if you are ranked #1 NN in that region for a minimum of 1 full month. 

<br>

## Notary Node regions

- Green: NA
- Yellow: EU
- Red: SH
- Blue: AR

![NN Regions](https://github.com/komodoplatform/dpow/blob/master/doc/img/NN_regions.jpeg)

<br>

## Guideline, general infos and policies 


### Important dates for Season 5:

- KMD snapshot: April 2nd 2021, 12pm UTC (for both VOTE2021 allocations and Regional Top 3 Notary Node scoring)
- Vote2021 airdrop: April 9th 2021, 12pm UTC
- Season 5 Election start: April 9nd 2021, 12pm UTC
- Regional Top 3 Autoelection announcement: April 9th 2021
- Proposal deadline: April 17th 2021, 12pm UTC
- Season 5 Election end: April 23rd 2021, 12pm UTC
- Public Komodo update announcement: April 30th, 2021
- dPoW season 5 start: June 14th, 2021

### Komodo Core and AC hardfork activation:

- Komodo core hardfork activation: KMD block `2.437.000` (Monday, June 14th, 2021)
- SmartChain hardfork activation: Timestamp `1623682800` (Monday, June 14th, 2021 03:00:00 PM UTC)

### The Komodo Mining ecosystem:

The Komodo mining ecosystem is exceptional in that a large part of the mining revenue (~75%) is reserved for the Notary Nodes, as they provide the network with the dPoW service and basically maintain the BTC security level. Thus the regular PoW miners on the Komodo network are eligible for approximately 25% of the mining revenue. 

### Automatic reelection:

The top 12 NNs get automatically re-elected. Only top 3 spots per region are eligible for the auto-reelection. The other 44 public NN spots are claimable through the annual NN elections.

### Notary scoring:

To determine relative participation notary scoring, refer to the following:

- KMD -> BTC Notarisation: 0.0325 
- Smartchain -> KMD notarisation: 0.8698/(number of main server chains*, not including KMD/BTC)
- 3rd Party chain -> KMD notarisation: 0.0977/(number of active 3rd party server chains*, not including KMD) 

Notarisation counts to be determined from decoded notarisation transaction OP_RETURN data on KMD block chain.

\* *As listed in https://github.com/KomodoPlatform/dPoW/blob/master/README.md*

### Developer Nodes:

Eight Nodes are reserved for the Komodo team for mining and experimental, debugging, or research operations, which include the usage of custom and experimental core code.

### Hunting unclaimed rewards:

The consensus rules allow every network participant to hunt the so-called “unclaimed reward blocks” which do contain additional mining-rewards.

### Mine Komodo blocks with your NN pubkey:

In the event a NN opts to hunt, as above, that NN must find some way to contribute block production to the network similar to the result of "traditional NN mining". This contribution shall be no less than 75% of the blocks produced by the region's leading block producing NN and in any event not below 15 blocks per day on average over the course of a calendar month. The contribution may be through means of only hunting part time, employing "external" hashrate full-time, or some combination of the two. This contribution shall <b>not</b> include mining several blocks in a short time with "external" hashrate and then abandoning the chain for a time, such an action does not produce a "similar result".

### NN gurus:

During the removal of the “NN master” role, the decision was made to create a new “NN guru” role, which does not have any authoritative power.

The NN gurus are the top NN operators of each region (ranked #1). These NN operators get the opportunity to be the NN guru if they hold rank 1 for at least one month. There is a tolerance timeframe of  1 month in which a NN guru could fall off his rank and still remain NN guru with the chance to climb back up. After a full month has passed with a new 1 rank, the NN guru role will be reassigned. 

NN gurus have additional duties and rights. They are “responsible” for their geo-region and should do their best to motivate, support, and push “weak” NN Operators to boost their region’s notarization statistics. NN gurus also support the Komodo team during the elections, initial setups, etc. In exchange the Komodo team will assign these NN gurus additional bounties and bonuses.

### NN judge:

A Komodo team-member that is not involved in the NN/dpow operations nor in the NN community gets the role of a NN judge assigned which will make a final decisions ref. rule violation and ban. The NN judge will be announced prior to the start of season 5. 

### NN tribunal:

Two additional team-members form together with the NN judge a NN tribunal which ensures an objective decision finding process in case of unclear situations and controversial debates related to a rule violation. The NN tribunal gets announced prior to the start of season 5.

#### The current NN gurus are:

CHMEX (@CHMEX#0686 on discord): EU region <br>
Shossain (@SHossain#0007 on discord): AR and NA region <br>
Strob (@Strob#3417): SH region <br>

### Rules and their enforcement - historic information for transparency:

In the previous Notary Node seasons, there were no protocolled rules or policies, which lead to certain confusion in the sense of the Latin phrase “nullum crimen, nulla poena sine lege,” which means someone cannot be punished for something that is not prohibited by law. 

We reconsidered this part and decided to author and publish these transparent guidelines which we call the “Notary Node Bible”. The Komodo team also decided that a violation of any of the above [rules](#responsibilities-rights-and-duties-of-a-nn) will lead to immediate loss of the NN spot. In the event that a single individual has a second violation in the following season, it would lead to disqualification from all future elections and seasons. 

A "grace period" at the beginning of Season 4 will apply until September 1st 2020, to allow for adjustment to rules based on the framework established in this document, and to give new notaries time to make mistakes, learn and tweak their servers. During this time, minor infractions may lead to "probationary status" with Gurus and the NN community assisting non-conforming operators achieve stable and productive participation. Major infractions (i.e. grossly negligent or malicious activity) will be suject to harsher penalty up to and including spot-loss / disqualification.

In case of such a spot-loss or disqualification, the next candidate from the election results will be eligible for the spot and the pubkey would be replaced with the next scheduled hardfork update. 

### NN season

A NN season may not equal 12 months - it will cover mininmum 75%, 3 quarters (9 months) of a year but could also last longer than a year under specific circumstances. 

### Notary Node setup:

You find all essential infos and setup instructions on https://github.com/KomodoPlatform/dPoW

#### Recommended min hardware setup for main NN: 
 
- OS: Ubuntu 18.x or Debian 10.x is recommended.
- CPU: A High-Performance CPU (e.g. Xeon, i7/i9, Ryzen, EPYC, etc.)
- RAM: 64 GB or more
- Disk: 1 TB SSD or greater
- Bandwidth: 100 Mbps or higher

#### Recommended min hardware setup for 3P NN: 
 
- OS: Ubuntu 18.x or Debian 10.x is recommended.
- CPU: A High-Performance CPU (e.g. Xeon, i7/i9, Ryzen, EPYC, etc.)
- RAM: 32 GB or more
- Disk: 500 GB SSD or greater
- Bandwidth: 100 Mbps or higher

### Polls and voting:

Polls are executed on github in form of an issue ticket and voting takes place by posting a signed message with your selection. A poll stays up for 30 days. Use the NN 3P KMD key for the sig. 


We reserve the right to amend this guideline (governing the participation in the dPoW operations) at any time. Modifications are transparently published on github. 

<br>

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
* Publishing other's private information, such as physical or electronic
  addresses, without explicit permission
* Other unethical or unprofessional conduct

Project maintainers have the right and responsibility to remove, edit, or reject comments, posts, commits, code, wiki edits, issues, and other contributions that are not aligned to this Code of Conduct, or to ban temporarily or permanently any contributor for other behaviors that they deem inappropriate, threatening, offensive, or harmful. Note that contributors may be volunteers who do not represent Komodo Platform. They are free to express their own opinions so long as they adhere to these guidelines.

By adopting this Code of Conduct, project maintainers commit themselves to fairly and consistently applying these principles to every aspect of managing this project. Project maintainers who do not follow or enforce the Code of Conduct may be permanently removed from the project team.

This Code of Conduct applies both within project spaces and in public spaces when an individual is representing the project or its community.

Instances of abusive, harassing, or otherwise unacceptable behavior may be reported by contacting a project maintainer (see below). All complaints will be reviewed and investigated and will result in a response that is deemed necessary and appropriate to the circumstances. Maintainers are obligated to maintain confidentiality with regard to the reporter of an incident.

You may send reports to developer@komodoplatform.com. 

If you wish to contact specific maintainers directly, the following have made themselves available for conduct issues:

- smk762 (smk762 at komodoplatform.com)
- TonyL (alysakov at komodoplatform.com)
- gcharang (gcharang at komodoplatform.com)
- ca333 (ca333 at komodoplatform.com)

This Code of Conduct is adapted from https://www.contributor-covenant.org/version/1/3/0/ 
https://www.contributor-covenant.org 

### Contact Info:


#### E-mail:

- alysakov@komodoplatform.com
- smk762@komodoplatform.com
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
