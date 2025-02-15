
# Touhou Puppet Play v2.0

![](https://repository-images.githubusercontent.com/430729681/04bd2d85-e736-42c2-bb00-c1c80e7df4c0)

![GitHub Repo stars](https://img.shields.io/github/stars/fatih120/thpuppetplay2?color=yellow&style=plastic) ![issues](https://img.shields.io/github/issues/fatih120/thpuppetplay2?color=red&style=plastic) ![GitHub commit activity](https://img.shields.io/github/commit-activity/m/fatih120/thpuppetplay2?style=plastic) ![enter image description here](https://img.shields.io/github/last-commit/fatih120/thpuppetplay2?style=plastic) 

This is a fork of the Pokémon Emerald Decompilation to create a modern, workable base to create Touhou Puppet Play hacks.

### Background

Due to the fragmented nature of the scene caused by many hacks of wildly varying quality ever since its conception, later made obsolete by the spiritual successor, [Touhou Puppet Dance Performance](http://tpdpwiki.net/wiki/Main_Page), much of THPP goes under the radar or is considered kusoge despite efforts put into hacks and fangames over the years. Recent developments have spiked in recent times (such as [Derxwna Kapsyla's Essentials edits](https://chaoticinfinitydev.tumblr.com/)), but nothing to consolidate a proper foundation to supersede the messy and nebulous task that is Pokémon binary ROM hacking.

## Enter thpuppetplay2

This self-declared v2.0 of Touhou Puppet Play will attempt to do the following:

* Retain all data in 1.812 as accurately as possible and import said data into the repository
* Expand the roster of puppets, whether via new forms or welcoming modern characters
  * Spritework which will be sourced from Hemoglobin, reimufate and others, and modified as see fit to narrow stylistic differences
 * Create a new BGM selection that aims for player enjoyment, not as a Pokémon mashup attempt
   * New samples and a centralized way to arrange music a milestone
* Assimilate quality-of-life changes, bug fixes, and major mechanic overhauls
  * Buffs and nerfs to puppets that will "unban" some and give weaker ones incentive
  * Modifications to give the player more customization and control, and give less need for a "speed-up" button
  * Touhou-ify UIs, implement few TPDP mechanics
 * And much more for end-users or those interested in demonstrations, whether they know how to edit C or not

thpuppetplay2 will have its official first release as a demonstration with a custom scenario, once this milestone is reached. Before then, this repository is considered a **heavy work-in-progress** that is not yet *intended* to be used by those who want to make a THPP hack, let alone expecting anything to be playable. Despite that, it is still able to be forked and used for any purposes (this is not a license).

## Install

Please refer to [INSTALL.md](INSTALL.md) to install a workspace and build thpuppetplay2.

## Contributing

You are welcome to make pull requests, though for major ideas with overhauls, engine changes, etc., it is highly recommended you discuss this in a casual sphere so that we are on the same page.

#### puppet.py

This is a script in the root directory (where it should also be used as the working directory). The usage is `puppet.py puppet <form>`, where `puppet` is a character's name (`reimu`) and `form` optionally being one of the evolutions, like `c`, `ad`, so on. Omit it for the main prefix-less evolution.
The script will add many lines and placeholders needed to add a new puppet into the game, saving some time. There is still manual work to be done after, which will all be printed afterwards.

### Credits

As the project is not considered ready for release, there is no cause for adhering to credits this early when much of the materials are not done by us.

* Fatih (Maintainer)
* Solitai7e (Co-Maintainer)
* へもぐろびんＡ１Ｃ (Dot, original work)
* all pret/pokeemerald contributors
* Touhou Puppet Play Community

------------

### Priority List:

| SSS Rank |  A Rank | B Renko  | Low  |
| :------------: | :------------: | :------------: | :------------: |
| Puppet data importing | Adding modern/new puppets | QoL things | Breeding Replacement System |
| Puppet interactions setup (movesets, levels, etc) | Gui/Strings/Sprites overhauled for the Touhou theme | Seal capture system | Elegant/Cute/Strong/Wise/Charismatic |
|  |  |  | Forms filter in dex to sort alphabetically |
