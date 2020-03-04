# Notary Node Bible v1



<b>Introduction:</b> This is the Komodo Platform Notary Node Bible, a compendium with essential information, instructions, rules, policies, election procedures for the Komodo Notary Node network, links to other important documents, and more. The NN bible comes into effect by the start of NN Season 4, which will be on May 31st, 2020. Election related rules apply for the Season 4 elections, with immediate effect. Please read carefully. 

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
 
<b>If you plan to run in the upcoming election, you have to submit your proposal to the Notary Node repository on [Github](https://github.com/KomodoPlatform/NotaryNodes/tree/master/season4/candidates) before March 16th, 2020. </b>
 
At a minimum, every candidate must announce the region in which they are running and post the address to which KMD holders may send their VOTE tokens. 
 
In general, the Komodo community elects Notary Node Operators who are committed to the development of the ecosystem. If your primary motivation is personal financial gain, you may find it difficult to garner support, even if you have proven your technical skills on Komodo’s test net.

Conversely, even if you are an ardent supporter of the Komodo ecosystem, you may fail to win a seat if your node is under-performing on the test net. A balance of both attributes — dedication to the Komodo ecosystem and strong technical abilities — is the ideal combination.

<br>

## The Notary Node election process
 
There are four Notary Node regions: Europe (EU), Asia-Russia (AR), North America (NA), and the Southern Hemisphere (SH). Each region contains at least 13 notary nodes, boosting the physical distribution and security of Komodo’s Notary Node network. In 2020, each region will have an even 15 Notary Nodes.
 
Those running for election must declare in which region they intend to operate their Notary Node. If anyone is discovered to be running a node in a region other than the one for which they were elected, this operator will be immediately disqualified and the NN spot gets assigned to the next candidate in the election result list. This keeps things fair, as different geographic locations offer Internet connections at varying costs and speeds.
 
<b>Candidates may choose to run for one seat in one of the four regions. That means that, at the most, any individual candidate can seek 1 Notary Node position in their first election participation. </b>
 
If that candidate proves his reliability and ability to operate a NN by making it to the top 3 rankings for his region at the end of the season, he is able to apply for up to two additional NN spots in different regions for the next elections. Three is the maximum number of spots that any one candidate is permitted to seek.

The Komodo Notary Node Elections are stake weighted, meaning that those who hold more KMD have more voting power in the election. The process works as follows.
 
A special voting token — let’s call it VOTE2020 — will be airdropped to KMD holders at a 1:1 ratio. If you have 1000 KMD, you will receive 1000 VOTE2020 tokens.
 
The airdrop will take place on March 16th, 2020. The current supply of KMD is around 120 Million, so roughly 120 Million VOTE2020 tokens will be airdropped.
 
It’s important to note that you must hold you private keys in order to receive your VOTE2020 tokens. If you hold your KMD on a centralized exchange, then you do not hold your private keys and you will not receive any VOTE2020 tokens.
 
Once you’ve received your VOTE2020 tokens, you may cast your ballot by sending them to the candidate(s) of your choice. All candidates will publicly post an address and the community votes by sending the tokens to the candidate(s) they wish to see elected.
 
The only rule for voting is that any redistribution or sale of VOTE2020 tokens is strictly prohibited. Anyone caught selling VOTE2020 tokens will be disqualified from participating in the election.

It is also strictly prohibited to offer NN revenue shares (mining revenue share) to voters.

CEX (wallets) are excluded from voting and users are advised to vote only from wallets whose private keys they fully control. VOTE2020 token transactions from CEX wallets are not counted.
 
Apart from that, community members may vote for any candidates in any region. VOTE2020 tokens can be sent in any amount so there is no requirement to cast votes in any set percentages for any number of candidates in any region.
 
For instance, if you want to send 100% of your VOTE2020 tokens to a single candidate, you may do so. If you want to send 20% of your votes to five different candidates in a single region, you may do that, too. If you want to send an equal 25% of your votes to one candidate in each of the four regions, that’s also an option. There are no rules dictating how you cast your ballot.
 
Voting will be open for around three weeks, until April 6th. It is highly recommended that each community member read through the proposals of all the candidates before casting their vote. The proposals contain important information about how each candidate intends to help the Komodo ecosystem. 
 
All of the candidates' proposals, along with other useful information, will be posted on this new Komodo Notary Node Election GitHub repo.

<b>The top 30 NNs who will be auto-elected will be announced on March 15th. 30 Notary Node spots are available in the 2020 election. Starting with season 4 the automatic re-elections are reduced to 3 spots per region.

The elections start on March 16th with the airdrop of the Vote2020 tokens and end on April 6th. The Komodo Core update is planned for April 13th and the hardfork activation for May 31st, 2020. </b>


<br>

## Responsibilities (“rights and duties”) of a NN

Operating a Notary Node comes with various responsibilities but also grants you certain privileges for securing the Komodo network with dPoW.


### NN Duties:

- <b>i.</b> Keep your Notary Node up to date (daily maintenance, update and upgrade check) and secured (according to the industry's best practices).
- <b>ii.</b> Notarize all active dPoW assets and participating in all expected notarization rounds without any interruptions (this will be checked daily). 
- <b>iii.</b> Mine Komodo blocks with your NN pubkey.
- <b>iv.</b> Follow update instructions within 24 hours on an update announcement (do not run for a NN position unless you can guarantee daily maintenance).
- <b>v.</b> Reach at least 33% of your region’s best monthly NN notarization score. This is checked on the first day of each month, beginning one month after the new NN season has begun.
- <b>vi.</b> Help other NN Operators in need and keep an eye on your geo-regional statistics. The most reliable regions will receive additional benefits and bounties. 
- <b>vii.</b> Report any violation that you notice ASAP to the Komodo team through security@komodoplatform.com.
- <b>viii.</b> Participate in discussions and publish your improvement proposals on https://github.com/KomodoPlatform/dpow. (exempt from enforcement)
- <b>ix.</b> Physically separate your main and 3rd party NN operations by using different servers.
- <b>x.</b> Use ONLY the original dPoW and Komodo Core codebases. Any core or protocol modification, non-public optimization, or similar code changes, will lead to immediate loss of the spot and disqualification.
- <b>xi.</b> Operate your NN in the assigned region. Using hosting providers with DCs in other regions and obfuscating this by using IPs from other regions will lead to immediate disqualification. 
- <b>xii.</b> Subscribe to https://github.com/KomodoPlatform/dpow and react in a timely manner (<24h) to notifications and announcements.
- <b>xiii.</b> Selling a NN spot is prohibited. This rule applies to all forms of disposition (giveaway, renting,...).
- <b>xiv.</b> Notarization funds, deposited on your NN keys by the Komodo team, are reserved for dPoW operations - it is strictly prohibited to transfer this funds or to use them for anything other then notarizations. At the end of the NN season or if you lose your spot, all NN funds must be returned to the Komodo team. 

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


### Important dates for Season 4:

- KMD snapshot: March 13th, 2020
- Autoelection announcement: March 15th - cutoff time: March 15th 2020, 12pm UTC
- Proposal deadline: March 16th 2020, 12pm UTC
- Vote2020 airdrop: March 16th, 2020
- Season 4 Election start: March 16th 2020, 12pm UTC
- Season 4 Election end: April 6th 2020, 12pm UTC
- Public Komodo update announcement: April 13th, 2020
- dPoW season 4 start: May 31st, 2020

### Komodo Core and AC hardfork activation:

- Komodo core hardfork activation: KMD block `1.903.000` (Sunday, May 31st, 2020)
- SmartChain hardfork activation: Timestamp `1590926400` (Sunday, May 31st, 2020 12:00:00 PM UTC)

### The Komodo Mining ecosystem:

The Komodo mining ecosystem is exceptional in that a large part of the mining revenue (~75%) is reserved for the Notary Nodes, as they provide the network with the dPoW service and basically maintain the BTC security level. Thus the regular PoW miners on the Komodo network are eligible for approximately 25% of the mining revenue. 

### Automatic reelection:

The top 3 NNs (according to the new NN algorithm) get automatically re-elected. Only 3 spots per region are eligible for the auto-reelection. The other 48 public NN spots are claimable through the annual NN elections. 

### Developer Nodes:

Four Nodes are reserved for the Komodo team for mining and experimental, debugging, or research operations, which include the usage of custom and experimental core code.

### Hunting unclaimed rewards: 

The consensus rules allow every network participant to hunt the so-called “unclaimed reward blocks” which do contain additional mining-rewards. 

### NN gurus:

During the removal of the “NN master” role, the decision was made to create a new “NN guru” role, which does not have any authoritative power.

The NN gurus are the top NN operators of each region (ranked #1). These NN operators get the opportunity to be the NN guru if they hold rank 1 for at least one month. There is a tolerance timeframe of  1 month in which a NN guru could fall off his rank and still remain NN guru with the chance to climb back up. After a full month has passed with a new 1 rank, the NN guru role will be reassigned. 

NN gurus have additional duties and rights. They are “responsible” for their geo-region and should do their best to motivate, support, and push “weak” NN Operators to boost their region’s notarization statistics. NN gurus also support the Komodo team during the elections, initial setups, etc. In exchange the Komodo team will assign these NN gurus additional bounties and bonuses.

### NN judge:

A Komodo team-member that is not involved in the NN/dpow operations nor in the NN community gets the role of a NN judge assigned which will make a final decisions ref. rule violation and ban. The NN judge will be announced prior to the start of season 4. 

### NN tribunal:

Two additional team-members form together with the NN judge a NN tribunal which ensures an objective decision finding process in case of unclear situations and controversial debates related to a rule violation. The NN tribunal gets announced prior to the start of season 4.

#### The current NN gurus are:

PHBA2061 (@PHBA2061#2530 on discord): EU region <br>
Shossain (@SHossain#0007 on discord): AR region <br>
Strob (@Strob#3417 on discord): NA region <br>
Titomane (@titomane#3101): SH region <br>

### Rules and their enforcement:

In the previous Notary Node seasons, there were no protocolled rules or policies, which lead to certain confusion in the sense of the Latin phrase “nullum crimen, nulla poena sine lege,” which means someone cannot be punished for something that is not prohibited by law. 

We reconsidered this part and decided to author and publish these transparent guidelines which we call the “Notary Node Bible”. The Komodo team also decided that a violation of any of the above [rules](#responsibilities-rights-and-duties-of-a-nn) will lead to immediate loss of the NN spot. In the event that a single individual has a second violation in the following season, it would lead to disqualification from all future elections and seasons. 

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

- ca333 (ca333 at komodoplatform.com)
- Steve Lee (steve at komodoplatform.com)
- Support Team (support at komodoplatform.com)

This Code of Conduct is adapted from https://www.contributor-covenant.org/version/1/3/0/ 
https://www.contributor-covenant.org 

### Contact Info:


#### E-mail:
- ca333@komodoplatform.com
- alysakov@komodoplatform.com
- alright@komodoplatform.com
- kolo@komodoplatform.com 
- dpow@komodoplatform.com

#### Discord:
http://www.komodoplatform.com/discord

#### Github:
https://github.com/komodoplatform 

#### Emergency contact for vuln reports:
security@komodoplatform.com 





Please feel free to provide your feedback, objections and suggestions. 
