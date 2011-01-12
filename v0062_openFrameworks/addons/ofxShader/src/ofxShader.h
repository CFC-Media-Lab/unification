



<!DOCTYPE html>
<html>
<head>
 <link rel="icon" type="image/vnd.microsoft.icon" href="http://www.gstatic.com/codesite/ph/images/phosting.ico">
 
 <script type="text/javascript">
 
 
 
 var codesite_token = null;
 
 
 var logged_in_user_email = null;
 
 
 var relative_base_url = "";
 
 </script>
 
 
 <title>ofxShader.h - 
 kyle -
 
 Project Hosting on Google Code</title>
 <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" >
 <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1" >
 
 <meta name="ROBOTS" content="NOARCHIVE">
 
 <link type="text/css" rel="stylesheet" href="http://www.gstatic.com/codesite/ph/6191598954148986782/css/ph_core.css">
 
 <link type="text/css" rel="stylesheet" href="http://www.gstatic.com/codesite/ph/6191598954148986782/css/ph_detail.css" >
 
 
 <link type="text/css" rel="stylesheet" href="http://www.gstatic.com/codesite/ph/6191598954148986782/css/d_sb_20080522.css" >
 
 
 
<!--[if IE]>
 <link type="text/css" rel="stylesheet" href="http://www.gstatic.com/codesite/ph/6191598954148986782/css/d_ie.css" >
<![endif]-->
 <style type="text/css">
 .menuIcon.off { background: no-repeat url(http://www.gstatic.com/codesite/ph/images/dropdown_sprite.gif) 0 -42px }
 .menuIcon.on { background: no-repeat url(http://www.gstatic.com/codesite/ph/images/dropdown_sprite.gif) 0 -28px }
 .menuIcon.down { background: no-repeat url(http://www.gstatic.com/codesite/ph/images/dropdown_sprite.gif) 0 0; }
 
 
 
  tr.inline_comment {
 background: #fff;
 vertical-align: top;
 }
 div.draft, div.published {
 padding: .3em;
 border: 1px solid #999; 
 margin-bottom: .1em;
 font-family: arial, sans-serif;
 max-width: 60em;
 }
 div.draft {
 background: #ffa;
 } 
 div.published {
 background: #e5ecf9;
 }
 div.published .body, div.draft .body {
 padding: .5em .1em .1em .1em;
 max-width: 60em;
 white-space: pre-wrap;
 white-space: -moz-pre-wrap;
 white-space: -pre-wrap;
 white-space: -o-pre-wrap;
 word-wrap: break-word;
 font-size: 1em;
 }
 div.draft .actions {
 margin-left: 1em;
 font-size: 90%;
 }
 div.draft form {
 padding: .5em .5em .5em 0;
 }
 div.draft textarea, div.published textarea {
 width: 95%;
 height: 10em;
 font-family: arial, sans-serif;
 margin-bottom: .5em;
 }

 
 .nocursor, .nocursor td, .cursor_hidden, .cursor_hidden td {
 background-color: white;
 height: 2px;
 }
 .cursor, .cursor td {
 background-color: darkblue;
 height: 2px;
 display: '';
 }
 
 
.list {
 border: 1px solid white;
 margin-bottom:0;
}

 </style>
</head>
<body class="t4">
 <script type="text/javascript">
 var _gaq = _gaq || [];
 _gaq.push(
 ['siteTracker._setAccount', 'UA-18071-1'],
 ['siteTracker._trackPageview']);
 
 (function() {
 var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
 ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
 (document.getElementsByTagName('head')[0] || document.getElementsByTagName('body')[0]).appendChild(ga);
 })();
 </script>
<div class="headbg">
 <div id="gaia">
 
 <span>
 
 <a href="#" id="projects-dropdown" onclick="return false;"><u>My favorites</u> <small>&#9660;</small></a>
 | <a href="https://www.google.com/accounts/ServiceLogin?service=code&amp;ltmpl=phosting&amp;continue=http%3A%2F%2Fcode.google.com%2Fp%2Fkyle%2Fsource%2Fbrowse%2Ftrunk%2Fopenframeworks%2Faddons%2FofxShader%2Fsrc%2FofxShader.h&amp;followup=http%3A%2F%2Fcode.google.com%2Fp%2Fkyle%2Fsource%2Fbrowse%2Ftrunk%2Fopenframeworks%2Faddons%2FofxShader%2Fsrc%2FofxShader.h" onclick="_CS_click('/gb/ph/signin');"><u>Sign in</u></a>
 
 </span>

 </div>
 <div class="gbh" style="left: 0pt;"></div>
 <div class="gbh" style="right: 0pt;"></div>
 
 
 <div style="height: 1px"></div>
<!--[if lte IE 7]>
<div style="text-align:center;">
Your version of Internet Explorer is not supported. Try a browser that
contributes to open source, such as <a href="http://www.firefox.com">Firefox</a>,
<a href="http://www.google.com/chrome">Google Chrome</a>, or
<a href="http://code.google.com/chrome/chromeframe/">Google Chrome Frame</a>.
</div>
<![endif]-->




 <table style="padding:0px; margin: 0px 0px 10px 0px; width:100%" cellpadding="0" cellspacing="0">
 <tr style="height: 58px;">
 
 <td id="plogo">
 <a href="/p/kyle/">
 
 <img src="http://www.gstatic.com/codesite/ph/images/defaultlogo.png" alt="Logo">
 
 </a>
 </td>
 
 <td style="padding-left: 0.5em">
 
 <div id="pname">
 <a href="/p/kyle/">kyle</a>
 </div>
 <div id="psum">
 <a id="project_summary_link" href="/p/kyle/" >Addons and demos for Open Frameworks.</a>
 
 </div>
 
 </td>
 <td style="white-space:nowrap;text-align:right; vertical-align:bottom;">
 
 <form action="/hosting/search">
 <input size="30" name="q" value="" type="text">
 <input type="submit" name="projectsearch" value="Search projects" >
 </form>
 
 </tr>
 </table>

</div>

 
<div id="mt" class="gtb"> 
 <a href="/p/kyle/" class="tab ">Project&nbsp;Home</a> 
 
 
 
 
 <a href="/p/kyle/downloads/list" class="tab ">Downloads</a>
 
 
 
 
 
 <a href="/p/kyle/w/list" class="tab ">Wiki</a>
 
 
 
 
 
 <a href="/p/kyle/issues/list"
 class="tab ">Issues</a>
 
 
 
 
 
 <a href="/p/kyle/source/checkout"
 class="tab active">Source</a>
 
 
 
 <div class=gtbc></div>
</div>
<table cellspacing="0" cellpadding="0" width="100%" align="center" border="0" class="st">
 <tr>
 
 
 
 
 
 
 <td class="subt">
 <div class="st2">
 <div class="isf">
 
 
 
 <span class="inst1"><a href="/p/kyle/source/checkout">Checkout</a></span> &nbsp;
 <span class="inst2"><a href="/p/kyle/source/browse/">Browse</a></span> &nbsp;
 <span class="inst3"><a href="/p/kyle/source/list">Changes</a></span> &nbsp;
 
 <form action="http://www.google.com/codesearch" method="get" style="display:inline"
 onsubmit="document.getElementById('codesearchq').value = document.getElementById('origq').value + ' package:http://kyle\\.googlecode\\.com'">
 <input type="hidden" name="q" id="codesearchq" value="">
 <input type="text" maxlength="2048" size="38" id="origq" name="origq" value="" title="Google Code Search" style="font-size:92%">&nbsp;<input type="submit" value="Search Trunk" name="btnG" style="font-size:92%">
 
 
 
 </form>
 </div>
</div>

 </td>
 
 
 
 <td align="right" valign="top" class="bevel-right"></td>
 </tr>
</table>
<script type="text/javascript">
 var cancelBubble = false;
 function _go(url) { document.location = url; }
</script>


<div id="maincol"
 
>

 
<!-- IE -->




<div class="expand">
<div id="colcontrol">


<style type="text/css">
 #file_flipper { display: inline; float: right; white-space: nowrap; }
 #file_flipper.hidden { display: none; }
 #file_flipper .pagelink { color: #0000CC; text-decoration: underline; }
 #file_flipper #visiblefiles { padding-left: 0.5em; padding-right: 0.5em; }
</style>
<div id="nav_and_rev" class="heading">
 <div class="list">
 <div class="pagination" style="margin-left: 2em">
 <table cellpadding="0" cellspacing="0" class="flipper">
 <tbody>
 <tr>
 
 <td>
 <ul class="leftside">
 
 <li><a href="/p/kyle/source/browse/trunk/openframeworks/addons/ofxShader/src/ofxShader.h?r=81" title="Previous">&lsaquo;r81</a></li>
 
 </ul>
 </td>
 
 <td><b>r98</b></td>
 
 </tr>
 </tbody>
 </table>
 </div>
 
 <div class="" style="vertical-align: top">
 <div class="src_crumbs src_nav">
 <strong class="src_nav">Source path:&nbsp;</strong>
 <span id="crumb_root">
 
 <a href="/p/kyle/source/browse/">svn</a>/&nbsp;</span>
 <span id="crumb_links" class="ifClosed"><a href="/p/kyle/source/browse/trunk/">trunk</a><span class="sp">/&nbsp;</span><a href="/p/kyle/source/browse/trunk/openframeworks/">openframeworks</a><span class="sp">/&nbsp;</span><a href="/p/kyle/source/browse/trunk/openframeworks/addons/">addons</a><span class="sp">/&nbsp;</span><a href="/p/kyle/source/browse/trunk/openframeworks/addons/ofxShader/">ofxShader</a><span class="sp">/&nbsp;</span><a href="/p/kyle/source/browse/trunk/openframeworks/addons/ofxShader/src/">src</a><span class="sp">/&nbsp;</span>ofxShader.h</span>
 
 
 
 </div>
 
 </div>
 <div style="clear:both"></div>
 </div>
</div>


<div class="fc">
 
 
 
<style type="text/css">
.undermouse span {
 background-image: url(http://www.gstatic.com/codesite/ph/images/comments.gif); }
</style>
<table class="opened" id="review_comment_area"
><tr>
<td id="nums">
<pre><table width="100%"><tr class="nocursor"><td></td></tr></table></pre>
<pre><table width="100%" id="nums_table_0"><tr id="gr_svn98_1"

><td id="1"><a href="#1">1</a></td></tr
><tr id="gr_svn98_2"

><td id="2"><a href="#2">2</a></td></tr
><tr id="gr_svn98_3"

><td id="3"><a href="#3">3</a></td></tr
><tr id="gr_svn98_4"

><td id="4"><a href="#4">4</a></td></tr
><tr id="gr_svn98_5"

><td id="5"><a href="#5">5</a></td></tr
><tr id="gr_svn98_6"

><td id="6"><a href="#6">6</a></td></tr
><tr id="gr_svn98_7"

><td id="7"><a href="#7">7</a></td></tr
><tr id="gr_svn98_8"

><td id="8"><a href="#8">8</a></td></tr
><tr id="gr_svn98_9"

><td id="9"><a href="#9">9</a></td></tr
><tr id="gr_svn98_10"

><td id="10"><a href="#10">10</a></td></tr
><tr id="gr_svn98_11"

><td id="11"><a href="#11">11</a></td></tr
><tr id="gr_svn98_12"

><td id="12"><a href="#12">12</a></td></tr
><tr id="gr_svn98_13"

><td id="13"><a href="#13">13</a></td></tr
><tr id="gr_svn98_14"

><td id="14"><a href="#14">14</a></td></tr
><tr id="gr_svn98_15"

><td id="15"><a href="#15">15</a></td></tr
><tr id="gr_svn98_16"

><td id="16"><a href="#16">16</a></td></tr
><tr id="gr_svn98_17"

><td id="17"><a href="#17">17</a></td></tr
><tr id="gr_svn98_18"

><td id="18"><a href="#18">18</a></td></tr
><tr id="gr_svn98_19"

><td id="19"><a href="#19">19</a></td></tr
><tr id="gr_svn98_20"

><td id="20"><a href="#20">20</a></td></tr
><tr id="gr_svn98_21"

><td id="21"><a href="#21">21</a></td></tr
><tr id="gr_svn98_22"

><td id="22"><a href="#22">22</a></td></tr
><tr id="gr_svn98_23"

><td id="23"><a href="#23">23</a></td></tr
><tr id="gr_svn98_24"

><td id="24"><a href="#24">24</a></td></tr
><tr id="gr_svn98_25"

><td id="25"><a href="#25">25</a></td></tr
><tr id="gr_svn98_26"

><td id="26"><a href="#26">26</a></td></tr
><tr id="gr_svn98_27"

><td id="27"><a href="#27">27</a></td></tr
><tr id="gr_svn98_28"

><td id="28"><a href="#28">28</a></td></tr
><tr id="gr_svn98_29"

><td id="29"><a href="#29">29</a></td></tr
><tr id="gr_svn98_30"

><td id="30"><a href="#30">30</a></td></tr
><tr id="gr_svn98_31"

><td id="31"><a href="#31">31</a></td></tr
><tr id="gr_svn98_32"

><td id="32"><a href="#32">32</a></td></tr
><tr id="gr_svn98_33"

><td id="33"><a href="#33">33</a></td></tr
><tr id="gr_svn98_34"

><td id="34"><a href="#34">34</a></td></tr
><tr id="gr_svn98_35"

><td id="35"><a href="#35">35</a></td></tr
><tr id="gr_svn98_36"

><td id="36"><a href="#36">36</a></td></tr
><tr id="gr_svn98_37"

><td id="37"><a href="#37">37</a></td></tr
><tr id="gr_svn98_38"

><td id="38"><a href="#38">38</a></td></tr
><tr id="gr_svn98_39"

><td id="39"><a href="#39">39</a></td></tr
><tr id="gr_svn98_40"

><td id="40"><a href="#40">40</a></td></tr
><tr id="gr_svn98_41"

><td id="41"><a href="#41">41</a></td></tr
><tr id="gr_svn98_42"

><td id="42"><a href="#42">42</a></td></tr
><tr id="gr_svn98_43"

><td id="43"><a href="#43">43</a></td></tr
><tr id="gr_svn98_44"

><td id="44"><a href="#44">44</a></td></tr
><tr id="gr_svn98_45"

><td id="45"><a href="#45">45</a></td></tr
><tr id="gr_svn98_46"

><td id="46"><a href="#46">46</a></td></tr
><tr id="gr_svn98_47"

><td id="47"><a href="#47">47</a></td></tr
><tr id="gr_svn98_48"

><td id="48"><a href="#48">48</a></td></tr
><tr id="gr_svn98_49"

><td id="49"><a href="#49">49</a></td></tr
><tr id="gr_svn98_50"

><td id="50"><a href="#50">50</a></td></tr
><tr id="gr_svn98_51"

><td id="51"><a href="#51">51</a></td></tr
><tr id="gr_svn98_52"

><td id="52"><a href="#52">52</a></td></tr
><tr id="gr_svn98_53"

><td id="53"><a href="#53">53</a></td></tr
><tr id="gr_svn98_54"

><td id="54"><a href="#54">54</a></td></tr
><tr id="gr_svn98_55"

><td id="55"><a href="#55">55</a></td></tr
><tr id="gr_svn98_56"

><td id="56"><a href="#56">56</a></td></tr
><tr id="gr_svn98_57"

><td id="57"><a href="#57">57</a></td></tr
><tr id="gr_svn98_58"

><td id="58"><a href="#58">58</a></td></tr
><tr id="gr_svn98_59"

><td id="59"><a href="#59">59</a></td></tr
><tr id="gr_svn98_60"

><td id="60"><a href="#60">60</a></td></tr
><tr id="gr_svn98_61"

><td id="61"><a href="#61">61</a></td></tr
><tr id="gr_svn98_62"

><td id="62"><a href="#62">62</a></td></tr
><tr id="gr_svn98_63"

><td id="63"><a href="#63">63</a></td></tr
><tr id="gr_svn98_64"

><td id="64"><a href="#64">64</a></td></tr
><tr id="gr_svn98_65"

><td id="65"><a href="#65">65</a></td></tr
><tr id="gr_svn98_66"

><td id="66"><a href="#66">66</a></td></tr
><tr id="gr_svn98_67"

><td id="67"><a href="#67">67</a></td></tr
><tr id="gr_svn98_68"

><td id="68"><a href="#68">68</a></td></tr
><tr id="gr_svn98_69"

><td id="69"><a href="#69">69</a></td></tr
><tr id="gr_svn98_70"

><td id="70"><a href="#70">70</a></td></tr
><tr id="gr_svn98_71"

><td id="71"><a href="#71">71</a></td></tr
><tr id="gr_svn98_72"

><td id="72"><a href="#72">72</a></td></tr
><tr id="gr_svn98_73"

><td id="73"><a href="#73">73</a></td></tr
><tr id="gr_svn98_74"

><td id="74"><a href="#74">74</a></td></tr
><tr id="gr_svn98_75"

><td id="75"><a href="#75">75</a></td></tr
><tr id="gr_svn98_76"

><td id="76"><a href="#76">76</a></td></tr
><tr id="gr_svn98_77"

><td id="77"><a href="#77">77</a></td></tr
><tr id="gr_svn98_78"

><td id="78"><a href="#78">78</a></td></tr
><tr id="gr_svn98_79"

><td id="79"><a href="#79">79</a></td></tr
><tr id="gr_svn98_80"

><td id="80"><a href="#80">80</a></td></tr
><tr id="gr_svn98_81"

><td id="81"><a href="#81">81</a></td></tr
><tr id="gr_svn98_82"

><td id="82"><a href="#82">82</a></td></tr
><tr id="gr_svn98_83"

><td id="83"><a href="#83">83</a></td></tr
><tr id="gr_svn98_84"

><td id="84"><a href="#84">84</a></td></tr
><tr id="gr_svn98_85"

><td id="85"><a href="#85">85</a></td></tr
><tr id="gr_svn98_86"

><td id="86"><a href="#86">86</a></td></tr
><tr id="gr_svn98_87"

><td id="87"><a href="#87">87</a></td></tr
></table></pre>
<pre><table width="100%"><tr class="nocursor"><td></td></tr></table></pre>
</td>
<td id="lines">
<pre class="prettyprint"><table width="100%"><tr class="cursor_stop cursor_hidden"><td></td></tr></table></pre>
<pre class="prettyprint "><table id="src_table_0"><tr
id=sl_svn98_1

><td class="source">#pragma once<br></td></tr
><tr
id=sl_svn98_2

><td class="source"><br></td></tr
><tr
id=sl_svn98_3

><td class="source">/*<br></td></tr
><tr
id=sl_svn98_4

><td class="source">	todo: add support for attachment of multiple shaders<br></td></tr
><tr
id=sl_svn98_5

><td class="source">	if a uniform or attribute isn&#39;t available, this will cause an error<br></td></tr
><tr
id=sl_svn98_6

><td class="source">	make sure to catch and report that error.<br></td></tr
><tr
id=sl_svn98_7

><td class="source">*/<br></td></tr
><tr
id=sl_svn98_8

><td class="source"><br></td></tr
><tr
id=sl_svn98_9

><td class="source">#include &quot;ofMain.h&quot;<br></td></tr
><tr
id=sl_svn98_10

><td class="source">#include &lt;fstream&gt;<br></td></tr
><tr
id=sl_svn98_11

><td class="source"><br></td></tr
><tr
id=sl_svn98_12

><td class="source">class ofxShader {<br></td></tr
><tr
id=sl_svn98_13

><td class="source">public:<br></td></tr
><tr
id=sl_svn98_14

><td class="source">	ofxShader();<br></td></tr
><tr
id=sl_svn98_15

><td class="source">	~ofxShader();<br></td></tr
><tr
id=sl_svn98_16

><td class="source"><br></td></tr
><tr
id=sl_svn98_17

><td class="source">	void setup(string shaderName);<br></td></tr
><tr
id=sl_svn98_18

><td class="source">	void setup(string vertexName, string fragmentName);<br></td></tr
><tr
id=sl_svn98_19

><td class="source">	void setupInline(string vertexShaderSource, string fragmentShaderSource);<br></td></tr
><tr
id=sl_svn98_20

><td class="source">	void unload();<br></td></tr
><tr
id=sl_svn98_21

><td class="source"><br></td></tr
><tr
id=sl_svn98_22

><td class="source">	void begin();<br></td></tr
><tr
id=sl_svn98_23

><td class="source">	void end();<br></td></tr
><tr
id=sl_svn98_24

><td class="source"><br></td></tr
><tr
id=sl_svn98_25

><td class="source">	// set a texture reference<br></td></tr
><tr
id=sl_svn98_26

><td class="source">	void setTexture(const char* name, ofBaseHasTexture&amp; img, int textureLocation);<br></td></tr
><tr
id=sl_svn98_27

><td class="source">	void setTexture(const char* name, ofTexture&amp; img, int textureLocation);<br></td></tr
><tr
id=sl_svn98_28

><td class="source"><br></td></tr
><tr
id=sl_svn98_29

><td class="source">	// set a single uniform value<br></td></tr
><tr
id=sl_svn98_30

><td class="source">	void setUniform1i(const char* name, int v1);<br></td></tr
><tr
id=sl_svn98_31

><td class="source">	void setUniform2i(const char* name, int v1, int v2);<br></td></tr
><tr
id=sl_svn98_32

><td class="source">	void setUniform3i(const char* name, int v1, int v2, int v3);<br></td></tr
><tr
id=sl_svn98_33

><td class="source">	void setUniform4i(const char* name, int v1, int v2, int v3, int v4);<br></td></tr
><tr
id=sl_svn98_34

><td class="source"><br></td></tr
><tr
id=sl_svn98_35

><td class="source">	void setUniform1f(const char* name, float v1);<br></td></tr
><tr
id=sl_svn98_36

><td class="source">	void setUniform2f(const char* name, float v1, float v2);<br></td></tr
><tr
id=sl_svn98_37

><td class="source">	void setUniform3f(const char* name, float v1, float v2, float v3);<br></td></tr
><tr
id=sl_svn98_38

><td class="source">	void setUniform4f(const char* name, float v1, float v2, float v3, float v4);<br></td></tr
><tr
id=sl_svn98_39

><td class="source"><br></td></tr
><tr
id=sl_svn98_40

><td class="source">	// set an array of uniform values<br></td></tr
><tr
id=sl_svn98_41

><td class="source">	void setUniform1iv(const char* name, int* v, int count = 1);<br></td></tr
><tr
id=sl_svn98_42

><td class="source">	void setUniform2iv(const char* name, int* v, int count = 1);<br></td></tr
><tr
id=sl_svn98_43

><td class="source">	void setUniform3iv(const char* name, int* v, int count = 1);<br></td></tr
><tr
id=sl_svn98_44

><td class="source">	void setUniform4iv(const char* name, int* v, int count = 1);<br></td></tr
><tr
id=sl_svn98_45

><td class="source"><br></td></tr
><tr
id=sl_svn98_46

><td class="source">	void setUniform1fv(const char* name, float* v, int count = 1);<br></td></tr
><tr
id=sl_svn98_47

><td class="source">	void setUniform2fv(const char* name, float* v, int count = 1);<br></td></tr
><tr
id=sl_svn98_48

><td class="source">	void setUniform3fv(const char* name, float* v, int count = 1);<br></td></tr
><tr
id=sl_svn98_49

><td class="source">	void setUniform4fv(const char* name, float* v, int count = 1);<br></td></tr
><tr
id=sl_svn98_50

><td class="source"><br></td></tr
><tr
id=sl_svn98_51

><td class="source">	// set attributes that vary per vertex (look up the location before glBegin)<br></td></tr
><tr
id=sl_svn98_52

><td class="source">	GLint getAttributeLocation(const char* name);<br></td></tr
><tr
id=sl_svn98_53

><td class="source">	<br></td></tr
><tr
id=sl_svn98_54

><td class="source">	void setAttribute1s(GLint location, short v1);<br></td></tr
><tr
id=sl_svn98_55

><td class="source">	void setAttribute2s(GLint location, short v1, short v2);<br></td></tr
><tr
id=sl_svn98_56

><td class="source">	void setAttribute3s(GLint location, short v1, short v2, short v3);<br></td></tr
><tr
id=sl_svn98_57

><td class="source">	void setAttribute4s(GLint location, short v1, short v2, short v3, short v4);<br></td></tr
><tr
id=sl_svn98_58

><td class="source"><br></td></tr
><tr
id=sl_svn98_59

><td class="source">	void setAttribute1f(GLint location, float v1);<br></td></tr
><tr
id=sl_svn98_60

><td class="source">	void setAttribute2f(GLint location, float v1, float v2);<br></td></tr
><tr
id=sl_svn98_61

><td class="source">	void setAttribute3f(GLint location, float v1, float v2, float v3);<br></td></tr
><tr
id=sl_svn98_62

><td class="source">	void setAttribute4f(GLint location, float v1, float v2, float v3, float v4);<br></td></tr
><tr
id=sl_svn98_63

><td class="source"><br></td></tr
><tr
id=sl_svn98_64

><td class="source">	void setAttribute1d(GLint location, double v1);<br></td></tr
><tr
id=sl_svn98_65

><td class="source">	void setAttribute2d(GLint location, double v1, double v2);<br></td></tr
><tr
id=sl_svn98_66

><td class="source">	void setAttribute3d(GLint location, double v1, double v2, double v3);<br></td></tr
><tr
id=sl_svn98_67

><td class="source">	void setAttribute4d(GLint location, double v1, double v2, double v3, double v4);<br></td></tr
><tr
id=sl_svn98_68

><td class="source"><br></td></tr
><tr
id=sl_svn98_69

><td class="source">	void printActiveUniforms();<br></td></tr
><tr
id=sl_svn98_70

><td class="source">	void printActiveAttributes();<br></td></tr
><tr
id=sl_svn98_71

><td class="source"><br></td></tr
><tr
id=sl_svn98_72

><td class="source">	GLuint vertexShader;<br></td></tr
><tr
id=sl_svn98_73

><td class="source">	GLuint fragmentShader;<br></td></tr
><tr
id=sl_svn98_74

><td class="source">	GLuint program;<br></td></tr
><tr
id=sl_svn98_75

><td class="source"><br></td></tr
><tr
id=sl_svn98_76

><td class="source">protected:<br></td></tr
><tr
id=sl_svn98_77

><td class="source">	string loadTextFile(string filename);<br></td></tr
><tr
id=sl_svn98_78

><td class="source">	GLint getUniformLocation(const char* name);<br></td></tr
><tr
id=sl_svn98_79

><td class="source"><br></td></tr
><tr
id=sl_svn98_80

><td class="source">	void compileShader(GLuint shader, string source, string type);<br></td></tr
><tr
id=sl_svn98_81

><td class="source">	void checkProgramInfoLog(GLuint program);<br></td></tr
><tr
id=sl_svn98_82

><td class="source">	bool checkShaderLinkStatus(GLuint shader, string type);<br></td></tr
><tr
id=sl_svn98_83

><td class="source">	bool checkShaderCompileStatus(GLuint shader, string type);<br></td></tr
><tr
id=sl_svn98_84

><td class="source">	void checkShaderInfoLog(GLuint shader, string type);<br></td></tr
><tr
id=sl_svn98_85

><td class="source"><br></td></tr
><tr
id=sl_svn98_86

><td class="source">	bool bLoaded;<br></td></tr
><tr
id=sl_svn98_87

><td class="source">};<br></td></tr
></table></pre>
<pre class="prettyprint"><table width="100%"><tr class="cursor_stop cursor_hidden"><td></td></tr></table></pre>
</td>
</tr></table>
<script type="text/javascript">
 var lineNumUnderMouse = -1;
 
 function gutterOver(num) {
 gutterOut();
 var newTR = document.getElementById('gr_svn98_' + num);
 if (newTR) {
 newTR.className = 'undermouse';
 }
 lineNumUnderMouse = num;
 }
 function gutterOut() {
 if (lineNumUnderMouse != -1) {
 var oldTR = document.getElementById(
 'gr_svn98_' + lineNumUnderMouse);
 if (oldTR) {
 oldTR.className = '';
 }
 lineNumUnderMouse = -1;
 }
 }
 var numsGenState = {table_base_id: 'nums_table_'};
 var srcGenState = {table_base_id: 'src_table_'};
 var alignerRunning = false;
 var startOver = false;
 function setLineNumberHeights() {
 if (alignerRunning) {
 startOver = true;
 return;
 }
 numsGenState.chunk_id = 0;
 numsGenState.table = document.getElementById('nums_table_0');
 numsGenState.row_num = 0;
 srcGenState.chunk_id = 0;
 srcGenState.table = document.getElementById('src_table_0');
 srcGenState.row_num = 0;
 alignerRunning = true;
 continueToSetLineNumberHeights();
 }
 function rowGenerator(genState) {
 if (genState.row_num < genState.table.rows.length) {
 var currentRow = genState.table.rows[genState.row_num];
 genState.row_num++;
 return currentRow;
 }
 var newTable = document.getElementById(
 genState.table_base_id + (genState.chunk_id + 1));
 if (newTable) {
 genState.chunk_id++;
 genState.row_num = 0;
 genState.table = newTable;
 return genState.table.rows[0];
 }
 return null;
 }
 var MAX_ROWS_PER_PASS = 1000;
 function continueToSetLineNumberHeights() {
 var rowsInThisPass = 0;
 var numRow = 1;
 var srcRow = 1;
 while (numRow && srcRow && rowsInThisPass < MAX_ROWS_PER_PASS) {
 numRow = rowGenerator(numsGenState);
 srcRow = rowGenerator(srcGenState);
 rowsInThisPass++;
 if (numRow && srcRow) {
 if (numRow.offsetHeight != srcRow.offsetHeight) {
 numRow.firstChild.style.height = srcRow.offsetHeight + 'px';
 }
 }
 }
 if (rowsInThisPass >= MAX_ROWS_PER_PASS) {
 setTimeout(continueToSetLineNumberHeights, 10);
 } else {
 alignerRunning = false;
 if (startOver) {
 startOver = false;
 setTimeout(setLineNumberHeights, 500);
 }
 }
 }
 // Do 2 complete passes, because there can be races
 // between this code and prettify.
 startOver = true;
 setTimeout(setLineNumberHeights, 250);
 window.onresize = setLineNumberHeights;
</script>

 
 
 <div id="log">
 <div style="text-align:right">
 <a class="ifCollapse" href="#" onclick="_toggleMeta('', 'p', 'kyle', this)">Show details</a>
 <a class="ifExpand" href="#" onclick="_toggleMeta('', 'p', 'kyle', this)">Hide details</a>
 </div>
 <div class="ifExpand">
 
 <div class="pmeta_bubble_bg" style="border:1px solid white">
 <div class="round4"></div>
 <div class="round2"></div>
 <div class="round1"></div>
 <div class="box-inner">
 <div id="changelog">
 <p>Change log</p>
 <div>
 <a href="/p/kyle/source/detail?spec=svn98&r=94">r94</a>
 by kylecimcdonald
 on Oct 29, 2010
 &nbsp; <a href="/p/kyle/source/diff?spec=svn98&r=94&amp;format=side&amp;path=/trunk/openframeworks/addons/ofxShader/src/ofxShader.h&amp;old_path=/trunk/openframeworks/addons/ofxShader/src/ofxShader.h&amp;old=81">Diff</a>
 </div>
 <pre>major fixes to ofxShader involving
attributes</pre>
 </div>
 
 
 
 
 
 
 <script type="text/javascript">
 var detail_url = '/p/kyle/source/detail?r=94&spec=svn98';
 var publish_url = '/p/kyle/source/detail?r=94&spec=svn98#publish';
 // describe the paths of this revision in javascript.
 var changed_paths = [];
 var changed_urls = [];
 
 changed_paths.push('/trunk/openframeworks/addons/ofxShader/src/ofxShader.cpp');
 changed_urls.push('/p/kyle/source/browse/trunk/openframeworks/addons/ofxShader/src/ofxShader.cpp?r\x3d94\x26spec\x3dsvn98');
 
 
 changed_paths.push('/trunk/openframeworks/addons/ofxShader/src/ofxShader.h');
 changed_urls.push('/p/kyle/source/browse/trunk/openframeworks/addons/ofxShader/src/ofxShader.h?r\x3d94\x26spec\x3dsvn98');
 
 var selected_path = '/trunk/openframeworks/addons/ofxShader/src/ofxShader.h';
 
 
 function getCurrentPageIndex() {
 for (var i = 0; i < changed_paths.length; i++) {
 if (selected_path == changed_paths[i]) {
 return i;
 }
 }
 }
 function getNextPage() {
 var i = getCurrentPageIndex();
 if (i < changed_paths.length - 1) {
 return changed_urls[i + 1];
 }
 return null;
 }
 function getPreviousPage() {
 var i = getCurrentPageIndex();
 if (i > 0) {
 return changed_urls[i - 1];
 }
 return null;
 }
 function gotoNextPage() {
 var page = getNextPage();
 if (!page) {
 page = detail_url;
 }
 window.location = page;
 }
 function gotoPreviousPage() {
 var page = getPreviousPage();
 if (!page) {
 page = detail_url;
 }
 window.location = page;
 }
 function gotoDetailPage() {
 window.location = detail_url;
 }
 function gotoPublishPage() {
 window.location = publish_url;
 }
</script>

 
 <style type="text/css">
 #review_nav {
 border-top: 3px solid white;
 padding-top: 6px;
 margin-top: 1em;
 }
 #review_nav td {
 vertical-align: middle;
 }
 #review_nav select {
 margin: .5em 0;
 }
 </style>
 <div id="review_nav">
 <table><tr><td>Go to:&nbsp;</td><td>
 <select name="files_in_rev" onchange="window.location=this.value">
 
 <option value="/p/kyle/source/browse/trunk/openframeworks/addons/ofxShader/src/ofxShader.cpp?r=94&amp;spec=svn98"
 
 >...dons/ofxShader/src/ofxShader.cpp</option>
 
 <option value="/p/kyle/source/browse/trunk/openframeworks/addons/ofxShader/src/ofxShader.h?r=94&amp;spec=svn98"
 selected="selected"
 >...addons/ofxShader/src/ofxShader.h</option>
 
 </select>
 </td></tr></table>
 
 
 



 <div style="white-space:nowrap">
 Project members,
 <a href="https://www.google.com/accounts/ServiceLogin?service=code&amp;ltmpl=phosting&amp;continue=http%3A%2F%2Fcode.google.com%2Fp%2Fkyle%2Fsource%2Fbrowse%2Ftrunk%2Fopenframeworks%2Faddons%2FofxShader%2Fsrc%2FofxShader.h&amp;followup=http%3A%2F%2Fcode.google.com%2Fp%2Fkyle%2Fsource%2Fbrowse%2Ftrunk%2Fopenframeworks%2Faddons%2FofxShader%2Fsrc%2FofxShader.h"
 >sign in</a> to write a code review</div>


 
 </div>
 
 
 </div>
 <div class="round1"></div>
 <div class="round2"></div>
 <div class="round4"></div>
 </div>
 <div class="pmeta_bubble_bg" style="border:1px solid white">
 <div class="round4"></div>
 <div class="round2"></div>
 <div class="round1"></div>
 <div class="box-inner">
 <div id="older_bubble">
 <p>Older revisions</p>
 
 
 <div class="closed" style="margin-bottom:3px;" >
 <img class="ifClosed" onclick="_toggleHidden(this)" src="http://www.gstatic.com/codesite/ph/images/plus.gif" >
 <img class="ifOpened" onclick="_toggleHidden(this)" src="http://www.gstatic.com/codesite/ph/images/minus.gif" >
 <a href="/p/kyle/source/detail?spec=svn98&r=81">r81</a>
 by kylecimcdonald
 on Aug 08, 2010
 &nbsp; <a href="/p/kyle/source/diff?spec=svn98&r=81&amp;format=side&amp;path=/trunk/openframeworks/addons/ofxShader/src/ofxShader.h&amp;old_path=/trunk/openframeworks/addons/ofxShader/src/ofxShader.h&amp;old=80">Diff</a>
 <br>
 <pre class="ifOpened">removed unused logError function</pre>
 </div>
 
 <div class="closed" style="margin-bottom:3px;" >
 <img class="ifClosed" onclick="_toggleHidden(this)" src="http://www.gstatic.com/codesite/ph/images/plus.gif" >
 <img class="ifOpened" onclick="_toggleHidden(this)" src="http://www.gstatic.com/codesite/ph/images/minus.gif" >
 <a href="/p/kyle/source/detail?spec=svn98&r=80">r80</a>
 by kylecimcdonald
 on Aug 08, 2010
 &nbsp; <a href="/p/kyle/source/diff?spec=svn98&r=80&amp;format=side&amp;path=/trunk/openframeworks/addons/ofxShader/src/ofxShader.h&amp;old_path=/trunk/openframeworks/addons/ofxShader/src/ofxShader.h&amp;old=74">Diff</a>
 <br>
 <pre class="ifOpened">&quot;shader&quot; changed to &quot;program&quot; to
describe more accurately what's going
on. removed all ARB references in
favor of proper OpenGL 2.0. added and
fixed debugging info to correctly
...</pre>
 </div>
 
 <div class="closed" style="margin-bottom:3px;" >
 <img class="ifClosed" onclick="_toggleHidden(this)" src="http://www.gstatic.com/codesite/ph/images/plus.gif" >
 <img class="ifOpened" onclick="_toggleHidden(this)" src="http://www.gstatic.com/codesite/ph/images/minus.gif" >
 <a href="/p/kyle/source/detail?spec=svn98&r=74">r74</a>
 by kylecimcdonald
 on Jul 11, 2010
 &nbsp; <a href="/p/kyle/source/diff?spec=svn98&r=74&amp;format=side&amp;path=/trunk/openframeworks/addons/ofxShader/src/ofxShader.h&amp;old_path=/trunk/openframeworks/addons/ofxShader/src/ofxShader.h&amp;old=73">Diff</a>
 <br>
 <pre class="ifOpened">big mistake, not using textureLocation
when calling setUniform. except now it
wont let me use more than one texture
at a time...?</pre>
 </div>
 
 
 <a href="/p/kyle/source/list?path=/trunk/openframeworks/addons/ofxShader/src/ofxShader.h&start=94">All revisions of this file</a>
 </div>
 </div>
 <div class="round1"></div>
 <div class="round2"></div>
 <div class="round4"></div>
 </div>
 <div class="pmeta_bubble_bg" style="border:1px solid white">
 <div class="round4"></div>
 <div class="round2"></div>
 <div class="round1"></div>
 <div class="box-inner">
 <div id="fileinfo_bubble">
 <p>File info</p>
 
 <div>Size: 3230 bytes,
 87 lines</div>
 
 <div><a href="http://kyle.googlecode.com/svn/trunk/openframeworks/addons/ofxShader/src/ofxShader.h">View raw file</a></div>
 </div>
 
 </div>
 <div class="round1"></div>
 <div class="round2"></div>
 <div class="round4"></div>
 </div>
 </div>
 </div>


</div>
</div>
</div>

<script src="http://www.gstatic.com/codesite/ph/6191598954148986782/js/prettify/prettify.js"></script>
<script type="text/javascript">prettyPrint();</script>


<script src="http://www.gstatic.com/codesite/ph/6191598954148986782/js/source_file_scripts.js"></script>

 <script type="text/javascript" src="http://kibbles.googlecode.com/files/kibbles-1.3.1.comp.js"></script>
 <script type="text/javascript">
 var lastStop = null;
 var initilized = false;
 
 function updateCursor(next, prev) {
 if (prev && prev.element) {
 prev.element.className = 'cursor_stop cursor_hidden';
 }
 if (next && next.element) {
 next.element.className = 'cursor_stop cursor';
 lastStop = next.index;
 }
 }
 
 function pubRevealed(data) {
 updateCursorForCell(data.cellId, 'cursor_stop cursor_hidden');
 if (initilized) {
 reloadCursors();
 }
 }
 
 function draftRevealed(data) {
 updateCursorForCell(data.cellId, 'cursor_stop cursor_hidden');
 if (initilized) {
 reloadCursors();
 }
 }
 
 function draftDestroyed(data) {
 updateCursorForCell(data.cellId, 'nocursor');
 if (initilized) {
 reloadCursors();
 }
 }
 function reloadCursors() {
 kibbles.skipper.reset();
 loadCursors();
 if (lastStop != null) {
 kibbles.skipper.setCurrentStop(lastStop);
 }
 }
 // possibly the simplest way to insert any newly added comments
 // is to update the class of the corresponding cursor row,
 // then refresh the entire list of rows.
 function updateCursorForCell(cellId, className) {
 var cell = document.getElementById(cellId);
 // we have to go two rows back to find the cursor location
 var row = getPreviousElement(cell.parentNode);
 row.className = className;
 }
 // returns the previous element, ignores text nodes.
 function getPreviousElement(e) {
 var element = e.previousSibling;
 if (element.nodeType == 3) {
 element = element.previousSibling;
 }
 if (element && element.tagName) {
 return element;
 }
 }
 function loadCursors() {
 // register our elements with skipper
 var elements = CR_getElements('*', 'cursor_stop');
 var len = elements.length;
 for (var i = 0; i < len; i++) {
 var element = elements[i]; 
 element.className = 'cursor_stop cursor_hidden';
 kibbles.skipper.append(element);
 }
 }
 function toggleComments() {
 CR_toggleCommentDisplay();
 reloadCursors();
 }
 function keysOnLoadHandler() {
 // setup skipper
 kibbles.skipper.addStopListener(
 kibbles.skipper.LISTENER_TYPE.PRE, updateCursor);
 // Set the 'offset' option to return the middle of the client area
 // an option can be a static value, or a callback
 kibbles.skipper.setOption('padding_top', 50);
 // Set the 'offset' option to return the middle of the client area
 // an option can be a static value, or a callback
 kibbles.skipper.setOption('padding_bottom', 100);
 // Register our keys
 kibbles.skipper.addFwdKey("n");
 kibbles.skipper.addRevKey("p");
 kibbles.keys.addKeyPressListener(
 'u', function() { window.location = detail_url; });
 kibbles.keys.addKeyPressListener(
 'r', function() { window.location = detail_url + '#publish'; });
 
 kibbles.keys.addKeyPressListener('j', gotoNextPage);
 kibbles.keys.addKeyPressListener('k', gotoPreviousPage);
 
 
 }
 </script>
<script src="http://www.gstatic.com/codesite/ph/6191598954148986782/js/code_review_scripts.js"></script>
<script type="text/javascript">
 
 // the comment form template
 var form = '<div class="draft"><div class="header"><span class="title">Draft comment:</span></div>' +
 '<div class="body"><form onsubmit="return false;"><textarea id="$ID">$BODY</textarea><br>$ACTIONS</form></div>' +
 '</div>';
 // the comment "plate" template used for both draft and published comment "plates".
 var draft_comment = '<div class="draft" ondblclick="$ONDBLCLICK">' +
 '<div class="header"><span class="title">Draft comment:</span><span class="actions">$ACTIONS</span></div>' +
 '<pre id="$ID" class="body">$BODY</pre>' +
 '</div>';
 var published_comment = '<div class="published">' +
 '<div class="header"><span class="title"><a href="$PROFILE_URL">$AUTHOR:</a></span><div>' +
 '<pre id="$ID" class="body">$BODY</pre>' +
 '</div>';

 function showPublishInstructions() {
 var element = document.getElementById('review_instr');
 if (element) {
 element.className = 'opened';
 }
 }
 function revsOnLoadHandler() {
 // register our source container with the commenting code
 var paths = {'svn98': '/trunk/openframeworks/addons/ofxShader/src/ofxShader.h'}
 CR_setup('', 'p', 'kyle', '', 'svn98', paths,
 '', CR_BrowseIntegrationFactory);
 // register our hidden ui elements with the code commenting code ui builder.
 CR_registerLayoutElement('form', form);
 CR_registerLayoutElement('draft_comment', draft_comment);
 CR_registerLayoutElement('published_comment', published_comment);
 
 CR_registerActivityListener(CR_ACTIVITY_TYPE.REVEAL_DRAFT_PLATE, showPublishInstructions);
 
 CR_registerActivityListener(CR_ACTIVITY_TYPE.REVEAL_PUB_PLATE, pubRevealed);
 CR_registerActivityListener(CR_ACTIVITY_TYPE.REVEAL_DRAFT_PLATE, draftRevealed);
 CR_registerActivityListener(CR_ACTIVITY_TYPE.DISCARD_DRAFT_COMMENT, draftDestroyed);
 
 
 
 
 
 
 
 var initilized = true;
 reloadCursors();
 }
 window.onload = function() {keysOnLoadHandler(); revsOnLoadHandler();};

</script>
<script type="text/javascript" src="http://www.gstatic.com/codesite/ph/6191598954148986782/js/dit_scripts.js"></script>

 
 
 <script type="text/javascript" src="http://www.gstatic.com/codesite/ph/6191598954148986782/js/core_scripts_20081103.js"></script>
 <script type="text/javascript" src="/js/codesite_product_dictionary_ph.pack.04102009.js"></script>
 </div>
<div id="footer" dir="ltr">
 
 <div class="text">
 
 &copy;2010 Google -
 <a href="/projecthosting/terms.html">Terms</a> -
 <a href="http://www.google.com/privacy.html">Privacy</a> -
 <a href="/p/support/">Project Hosting Help</a>
 
 </div>
</div>

 <div class="hostedBy" style="margin-top: -20px;">
 <span style="vertical-align: top;">Powered by <a href="http://code.google.com/projecthosting/">Google Project Hosting</a></span>
 </div>
 
 


 
 </body>
</html>

