%define debug_package %{nil}
%define _build_id_links none
%define name mcs_mk
%define version 1.0.0
%define repository gemdev
%define _prefix /gem_base/epics/ioc
%define arch %(uname -m)
%define checkout %(git log --pretty=format:'%h' -n 1)
%define git_hash %(git rev-parse --short HEAD 2>/dev/null || echo "nogit")

%global _enable_debug_package 0
%global debug_package %{nil}
%global __os_install_post /usr/lib/rpm/brp-compress %{nil}

Summary: %{name} Package
Name: %{name}
Version: %{version}
Release: 8.git%{git_hash}%{?dist}
License: EPICS Open License
Group: Applications/Engineering
Source0: %{name}-%{version}.tar.gz
ExclusiveArch: %{arch}
Prefix: %{_prefix}
BuildRequires: re2c 
BuildRequires: tdct
BuildRequires: epics-base-devel  = 7.0.7-0.git.f9e3717%{?dist}
BuildRequires: sequencer-devel   = 2.2.9.e5e3615-4.git.7b11f25%{?dist}
BuildRequires: autosave-devel    = 5.10.2-0.git.57f0212%{?dist}
BuildRequires: bancomm-devel     = 1.6.13-4.git.6f4ba7b%{?dist}
BuildRequires: geminiRec-devel   = 4.1.13-3.git.6f58677%{?dist}
BuildRequires: timelib-devel     = 2.1.4-3.git.a504360%{?dist}
BuildRequires: pmaclib-devel     = 1.1.12-2.git.955fcac%{?dist}
BuildRequires: slalib-devel      = 1.9.7-6.git.54d124d%{?dist}
BuildRequires: xycom-devel       = 2.1.12-2.git.e8d8b00%{?dist}
BuildRequires: gemUtil-devel     = 1.6.13-2.git.9268b49%{?dist}
BuildRequires: timeProbe-devel   = 1.1.16-3.git.1bb32b7%{?dist}
BuildRequires: pvload-devel      = 1.2.1-7.git.6df46ce%{?dist}


#Requires: epics-base sequencer autosave bancomm geminiRec timelib pmaclib slalib xycom gemUtil timeProbe pvload
## Switch dependency checking off
AutoReqProv: no

%description
This is the module %{name}.

## If you want to have a devel-package to be generated uncomment the following:
%package devel
Summary: %{name}-devel Package
Group: Development/Gemini
Requires: %{name} = %{version}-%{release}
Requires: re2c 
Requires: tdct
Requires: epics-base-devel  = 7.0.7-0.git.f9e3717%{?dist}
Requires: sequencer-devel   = 2.2.9.e5e3615-4.git.7b11f25%{?dist}
Requires: autosave-devel    = 5.10.2-0.git.57f0212%{?dist}
Requires: bancomm-devel     = 1.6.13-4.git.6f4ba7b%{?dist}
Requires: geminiRec-devel   = 4.1.13-3.git.6f58677%{?dist}
Requires: timelib-devel     = 2.1.4-3.git.a504360%{?dist}
Requires: pmaclib-devel     = 1.1.12-2.git.955fcac%{?dist}
Requires: slalib-devel      = 1.9.7-6.git.54d124d%{?dist}
Requires: xycom-devel       = 2.1.12-2.git.e8d8b00%{?dist}
Requires: gemUtil-devel     = 1.6.13-2.git.9268b49%{?dist}
Requires: timeProbe-devel   = 1.1.16-3.git.1bb32b7%{?dist}
Requires: pvload-devel      = 1.2.1-7.git.6df46ce%{?dist}
#Requires: %{name} tdct sequencer-devel autosave-devel  bancomm-devel geminiRec-devel timelib-devel pmaclib-devel slalib-devel xycom-devel gemUtil-devel timeProbe-devel pvload-devel
%description devel
This is the module %{name}.

%prep
%setup -q 

%build
#update environment from former rpm installations due to BuildRequires
source /gem_base/etc/profile
#start virtual framebuffer to have graphics for java
#Xvfb :1  -ac -nolisten tcp -nolisten unix &

make distclean uninstall
#DISPLAY=:1 make
make
#killall Xvfb

%install
export DONT_STRIP=1
rm -rf $RPM_BUILD_ROOT
mkdir -p $RPM_BUILD_ROOT/%{_prefix}/%{name}
cp -r dbd $RPM_BUILD_ROOT/%{_prefix}/%{name}
cp -r db $RPM_BUILD_ROOT/%{_prefix}/%{name}
cp -r bin $RPM_BUILD_ROOT/%{_prefix}/%{name}
cp -r include $RPM_BUILD_ROOT/%{_prefix}/%{name}
cp -r configure $RPM_BUILD_ROOT/%{_prefix}/%{name}


%postun
if [ "$1" = "0" ]; then
	rm -rf %{_prefix}/%{name}
fi


%clean
rm -rf $RPM_BUILD_ROOT

%files
%defattr(-,root,root)
   /%{_prefix}/%{name}/bin
   /%{_prefix}/%{name}/db
   /%{_prefix}/%{name}/dbd
   /%{_prefix}/%{name}/include
   /%{_prefix}/%{name}/configure


%files devel
%defattr(-,root,root)
   /%{_prefix}/%{name}/db
   /%{_prefix}/%{name}/dbd
   /%{_prefix}/%{name}/include
   /%{_prefix}/%{name}/configure

%changelog
* Mon Jun 13 2022 Cristian Urrutia <cristian.urrutia@noirlab.edu> 
- new package built with tito

