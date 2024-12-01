Dogpu Core integration/staging tree
=====================================

https://DogeGPU.com

To see how to run DogeGPU, please read the respective files in [the doc folder](doc)

Introduction
------------

In the rapidly evolving landscape of cryptocurrencies, speed, efficiency, and accessibility have become paramount. DogeGPU emerges as the official cryptocurrency of Mars. It surpasses both Bitcoin and Dogecoin by offering ultra-fast 15-second block times. While Bitcoin's antiquated 10-minute block times often lead to delayed transaction confirmations and network congestion, unusable episodes, DogeGPU accelerates transaction processing, enhancing network responsiveness and providing a seamless user experience. This significant reduction in block time means that DogeGPU processes transactions 4X faster than Dogecoin (which has a 1-minute block time) and up to 40x faster than Bitcoin, effectively addressing the scalability issues inherent in older blockchains.
By merging the beloved community spirit of Dogecoin with advanced GPU-optimized mining algorithms, DogeGPU not only democratizes mining but also revolutionizes transaction speed and efficiency. It represents a new era of cryptocurrency where transactions are swift, mining is accessible, and the community thrives—all while leaving the competition in the "dog" house due to their sluggish performance. With DogeGPU, the future of digital currency is not just fast—it's instantaneous.


What is DogeGPU?
----------------

DogeGPU is an experimental digital currency that enables instant payments to
anyone, anywhere in the world.
DogeGPU uses peer-to-peer technology to operate
with no central authority: managing transactions and issuing money are carried
out collectively by the network. 



License
-------

Dogpu Core is released under the terms of the MIT license. See [COPYING](COPYING) for more
information or see https://opensource.org/licenses/MIT.

Development Process
-------------------

The `master` branch is regularly built and tested, but is not guaranteed to be
completely stable. [Tags](https://github.com/Masterscooper/DogeGPU/tags) are created
regularly to indicate new official, stable release versions of Dogpu Core.

Active development is done in the `develop` branch. 

The contribution workflow is described in [CONTRIBUTING.md](CONTRIBUTING.md).

Developer IRC is inactive please join us on discord in #development. https://discord.gg/fndp4NBGct

Testing
-------

Testing and code review is the bottleneck for development; we get more pull
requests than we can review and test on short notice. Please be patient and help out by testing
other people's pull requests, and remember this is a security-critical project where any mistake might cost people
lots of money.

Testnet is up and running and available to use during development.

### Automated Testing

Developers are strongly encouraged to write [unit tests](src/test/README.md) for new code, and to
submit new unit tests for old code. Unit tests can be compiled and run
(assuming they weren't disabled in configure) with: `make check`. Further details on running
and extending unit tests can be found in [/src/test/README.md](/src/test/README.md).

There are also [regression and integration tests](/test), written
in Python, that are run automatically on the build server.
These tests can be run (if the [test dependencies](/test) are installed) with: `test/functional/test_runner.py`


### Manual Quality Assurance (QA) Testing

Changes should be tested by somebody other than the developer who wrote the
code. This is especially important for large or high-risk changes. It is useful
to add a test plan to the pull request description if testing the changes is
not straightforward.


About DogeGPU
----------------
A digital peer to peer network for the facilitation of asset transfer.

DogeGPU is a use case specific blockchain designed to carry fast and secure transactions.

Thank you to the Bitcoin developers. 

The DogeGPU project is launched based on the hard work and continuous effort of over 400 Bitcoin developers who made over 14,000 commits over the life to date of the Bitcoin project. We are eternally grateful to you for your efforts and diligence in making a secure network and for their support of free and open source software development.  The DogeGPU experiment is made on the foundation you built.


Abstract
----------------
DogeGPU aims to implement a blockchain which is optimized specifically for the use case of transferring information from one holder to another. Based on the extensive development and testing of Bitcoin, DogeGPU is built on a fork of the Bitcoin code. Key changes include a faster block reward time and a change in the number, but not weighed distribution schedule, of coins. DogeGPU is free and open source and will be issued and mined transparently with no pre-mine, developer allocation or any other similar set aside. DogeGPU is intended to prioritize user control, privacy and censorship resistance and be jurisdiction agnostic while allowing simple optional additional features for users based on need.



A blockchain is a ledger showing the value of something and allowing it to be transferred to someone else. Of all the possible uses for blockchains, the reporting of who owns what is one of the core uses of the technology.  This is why the first and most successful use case for blockchain technology to date has been Bitcoin.

DogeGPU is designed to be a use case specific blockchain designed to efficiently handle one specific function: Fast Secure Transfers

Bitcoin is and always should be focused on its goals of being a better form of money however it is more than apparent the long blocktimes are out dated. Bitcoin developers will unlikely prioritize improvements or features which are specifically beneficial to the facilitation of token transfers.  One goal of the DogeGPU project is to see if a use case specific blockchain and development effort can create code which can either improve existing structures like Bitcoin or provide advantages for specific use cases.

For such a global system to work it will need to be independent of regulatory jurisdictions.  This is not due to ideological belief but practicality: if the rails for blockchain asset transfer are not censorship resistance and jurisdiction agnostic, any given jurisdiction may be in conflict with another.  In legacy systems, wealth was generally confined in the jurisdiction of the holder and therefore easy to control based on the policies of that jurisdiction. Because of the global nature of blockchain technology any protocol level ability to control wealth would potentially place jurisdictions in conflict and will not be able to operate fairly.  

