import React, { Fragment, useState } from 'react';
import {
  Text, Button
} from 'react-native';

interface Props {
    name: string
}

interface State {
    fcName: string
}
const MyFirstFunctionalComponentWithState: React.FC<Props, State> = (props) => {
    const [fcName, setFCName] = useState(props.name);
    return(
        <Fragment>
            <Text>Hello from {fcName}</Text>
            <Button title="Click" onPress={() => setFCName("Mike")}/>
        </Fragment>
    )
}

export default MyFirstFunctionalComponentWithState;