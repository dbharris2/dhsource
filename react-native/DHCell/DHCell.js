/**
 * Generic Cell Component
 */

'use strict';

import React, {
  AppRegistry,
  Component,
  Image,
  StyleSheet,
  Text,
  View
} from 'react-native';

class DHCell extends Component {  
  render() {
    const imageComponent = this.props.uri != null ?
      <Image 
        source={{uri: this.props.uri}} 
        style={cellStyles.image}
        /> :
      null;
    
    const titleComponent = this.props.title != null ?
      <Text style={[cellStyles.text, cellStyles.title]}>
        {this.props.title}
      </Text> :
      null;
    
    const subtitleComponent = this.props.subtitle != null ?
      <Text style={[cellStyles.text, cellStyles.subtitle]}>
        {this.props.subtitle}
      </Text> :
      null;

    return (
      <View style={cellStyles.container}>
        {imageComponent}
        <View style={{flexDirection: 'column'}}>
          {titleComponent}
          {subtitleComponent}
        </View>
      </View>
    )
  }
}

const cellStyles = StyleSheet.create({
  container: {
    alignItems: 'center',
    backgroundColor: '#DDDDDD',
    flexDirection: 'row',
  },
  image: {
    height: 60,
    width: 60,
  },
  subtitle: {
    fontSize: 14,
  },
  text: {
    marginHorizontal: 12,
  },
  title: {
    fontSize: 20,
  },
});

DHCell.propTypes = {
  subtitle: React.PropTypes.string,
  title: React.PropTypes.string.isRequired,
  uri: React.PropTypes.string.isRequired,
};

module.exports = DHCell;
